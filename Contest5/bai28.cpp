#include<bits/stdc++.h>
using namespace std;
int min(int x, int y, int z){
	return min(min(x, y), z);
}
void solve(string s1, string s2){
	int n = s1.size();
	int m = s2.size();
	int F[n+1][m+1];
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= m; j++){
			if (i == 0)
				F[i][j] = j;
			else if (j == 0)
				F[i][j] = i;
			else if (s1[i-1] == s2[j-1])
				F[i][j] = F[i-1][j-1];
			else
				F[i][j] = 1 + min(F[i][j-1], F[i-1][j], F[i-1][j-1]);
		}
	}
	cout << F[n][m] << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		string s1, s2;
		cin >> s1 >> s2;
		solve(s1, s2);
	}
}
