#include<bits/stdc++.h>
using namespace std;
int F[105][25005];
void solve(int c, int n, int w[]){
	for (int i = 0; i <= n; i++)
		F[i][0] = 0;
	for (int j = 0; j <= c; j++)
		F[0][j] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= c; j++){
			if (j >= w[i-1])
				F[i][j] = max(F[i-1][j], w[i-1] + F[i-1][j-w[i-1]]);
			else
				F[i][j] = F[i-1][j];
		}
	}
	cout << F[n][c] << endl;
}
int main(){
	int c, n, *w;
	cin >> c >> n;
	w = new int[n];
	for (int i = 0; i < n; i++) cin >> w[i];
	solve(c, n, w);
}
