#include<bits/stdc++.h>
using namespace std;
int F[1005][1005];
void solve(int n, int v, int a[], int c[]){
	for (int i = 0; i <= n; i++)
		F[i][0] = 0;
	for (int j = 0; j <= v; j++)
		F[0][j] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= v; j++){
			if (j >= a[i-1])
				F[i][j] = max(F[i-1][j], c[i-1] + F[i-1][j-a[i-1]]);
			else
				F[i][j] = F[i-1][j];
		}
	}
	cout << F[n][v] << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		int n, v, *a, *c;
		cin >> n >> v;
		a = new int[n]; c= new int [n];
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> c[i];
		solve(n, v, a, c);
		delete a; delete c;
	}
}
