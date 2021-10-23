#include <bits/stdc++.h>
using namespace std;
int a[100000], b[100000], k=1;
int n , t;
vector<int> res;

int in(){
	int tong=0;
	for (int i = 1 ; i <= k ; i++){
		int c = a[i];
		tong += b[c];
	}
	if(tong == t) return k;
	else return 0;
}
void sinh(int i){
    for(int j = a[i-1]+1 ; j <= n-k+i ; j++){
        a[i] = j;
        if (i == k){
            if (in()!=0){
            	res.push_back(k);
            	k = 31;
			}
        }
        else{
            sinh(i+1) ;
        }
    }
}
void toHop(){
    while (k<=n ){
        a[0] = 0;
    	sinh(1);
    	k++;
    }
    if (res.empty()) cout << -1;
    else cout << res[0];
}
int main(){
	cin>>n;
    cin>>t;
    for(int i=1; i<=n; i++){
    	cin>>b[i];
	}
	toHop();
    return 0;
}
