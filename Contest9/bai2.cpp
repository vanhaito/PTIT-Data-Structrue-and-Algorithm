#include<bits/stdc++.h>
using namespace std;
int n;
int matrix[1005][1005];
int strToNum(string s){
	int res=0;
	for (int i=0; i<s.length(); i++)
		res = res*10+(s[i]-'0');
	return res;
}
int main(){
	int n; cin >> n;
	cin.ignore();
	memset(matrix, 0 , sizeof(matrix));
	for (int i=1; i<=n; i++){
		string s; getline(cin, s);
		stringstream ss;
		ss<<s;
		while (ss>>s){
			int tmp=strToNum(s);
			matrix[i][tmp] = 1;
		}
	}
	for (int i=1; i<n; i++){
		for (int j=i+1; j<=n; j++)
			if (matrix[i][j])
				cout<<i<<" "<<j<<endl;
	}
}
