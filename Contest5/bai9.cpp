#include<bits/stdc++.h>
typedef long long ll;
ll const mod = 1e9 + 7;
ll F[101][50005];
using namespace std;
int main(){
	for (int i = 0; i < 101; i++)
		F[i][0] = 0;
	for (int j = 0; j < 50005; j++)
		F[0][j] = 0;
	for (int j = 1; j <= 9; j++)
		F[1][j] = 1;
	for (int i = 1; i <= 100; i++)
		for (int k = 0; k <= 9; k++)
			for (int j = k; j <= 50000; j++)
				F[i][j] = (F[i][j]%mod + F[i-1][j-k]%mod) % mod;
	int T; cin >> T;
	while (T--){
		int n, sum;
		cin >> n >> sum;
		cout << F[n][sum] << endl;
	}
}
