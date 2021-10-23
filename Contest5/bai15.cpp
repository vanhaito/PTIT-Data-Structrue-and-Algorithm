#include<bits/stdc++.h>
using namespace std;
int F[105][105][105];
void solve(string X, string Y, string Z, int n, int m, int p){
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= m; j++){
			for (int k = 0; k <= p; k++){
				if (i == 0 || j == 0 || k == 0)
					F[i][j][k] = 0;
				else if (X[i-1] == Y[j-1] && X[i-1] == Z[k-1])
					F[i][j][k] = F[i-1][j-1][k-1] + 1;
				else
					F[i][j][k] = max(max(F[i-1][j][k], F[i][j-1][k]), F[i][j][k-1]);
			}
		}
	}
	cout << F[n][m][p] << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		int n, m, p;
		string X, Y, Z;
		cin >> n >> m >> p;
		cin >> X >> Y >> Z;
		solve(X, Y, Z, n, m, p);
	}
}
