#include<bits/stdc++.h>
using namespace std;

int n, k;
int X[100];
vector< vector<int> > result;

void solve(int a[], int &c){
	vector <int> b;
	int sum = 0;
	for(int i=1; i<=n; i++){
		if(a[i] == 1){
			sum += X[i];
			b.push_back(X[i]);
		}
	}
	if(sum == k){
		result.push_back(b);
		c++;
	}	
}

void Try(int i, int a[], int &c){
	for(int j=0; j<=1; j++){
		a[i] = j;
		if(i == n) solve(a, c);
		else Try(i+1, a, c);	
	}
}

int main(){
	int t; cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1; i<=n; i++)
			cin>>X[i];
		sort(X, X+n+1);
		result.clear();
		int c = 0;
		int a[100] = {};
		Try(1, a, c);
		sort(result.begin(),result.end());
		int i, j;
		if(c == 0) cout<<-1;
		else{
			for(i=0; i<c; i++){
				cout<<"[";
				for(j=0; j<result[i].size()-1; j++)
					cout<<result[i][j]<<" ";
				cout<<result[i][j]<<"] ";		
			}
		}
		cout<<endl;
	}
}
