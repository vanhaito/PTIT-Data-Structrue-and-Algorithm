#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve(int n, int m){
	ll F[n+1][m+1];
	for (int i = 0; i <= n; i++)
		F[i][0] = 1;
	for (int j = 0; j <= m; j++)
		F[0][j] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			F[i][j] = F[i-1][j] + F[i][j-1];
	cout << F[n][m] << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		int n, m;
		cin >> n >> m;
		solve(n, m);
	}
}
