#include <bits/stdc++.h> 
using namespace std; 
int a[105], n;

void init(){
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
}
bool solve(){
	int sum=0;
	for(int i=0; i<n; i++)
		sum+=a[i];
	if(sum%2!=0) return false;
	
	bool F[sum/2+1][n+1];
	for(int i=0; i<=n; i++)
		F[0][i]=true;
	for(int i=1; i<=sum/2; i++)
		F[i][0]=false;
		
	for(int i=1; i<=sum/2; i++){
		for(int j=1; j<=n; j++){
			F[i][j] = F[i][j-1];
			if(i>=a[j-1]){
				F[i][j] = F[i][j] || F[i-a[j-1]][j-1];
			}
		}
	}
	return F[sum/2][n];
}
int main(){
	int t; cin>>t;
	while(t--){
		init();
		if(solve()==true) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
