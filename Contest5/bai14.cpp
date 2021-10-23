#include<bits/stdc++.h>
using namespace std;
void solve(string s, int n){
	int F[n+1][n+1];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			F[i][j] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (s[i-1] == s[j-1] & i != j)
				F[i][j] = F[i-1][j-1] + 1;
			else
				F[i][j] = max(F[i-1][j], F[i][j-1]);
		}
	}
	cout << F[n][n] << endl;

}
int main(){
	int T; cin >> T;
	while (T--){
		int n; string s; 
		cin >> n; cin >> s;
		solve(s, n);
	}
}
