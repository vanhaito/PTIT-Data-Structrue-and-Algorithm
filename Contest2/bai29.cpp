#include<bits/stdc++.h>
using namespace std;
int m, n;
int a[100][100];

int paths(int m, int n){
	if (m == 1 || n == 1)
		return 1;
	return paths(m-1, n) + paths(m, n-1);
}

int main(){
	int t; cin>>t;
	while(t--){
		cin>>m>>n;
		for(int i=0; i < m; i++)
			for(int j=0; j < n; j++)
				cin>>a[i][j];
		cout<<paths(m, n)<<endl;
	}
}
