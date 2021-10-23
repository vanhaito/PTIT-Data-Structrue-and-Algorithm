#include<bits/stdc++.h>
typedef long long ll;
ll const mod = 1e9 + 7;
using namespace std;
ll nPk(int n, int k){
	ll P[k+10];
	memset(P, 0, sizeof(P));
	P[0] = 1;
	for (int i = 0; i <= n; i++){
		for (int j = min(i, k); j > 0; j--){
			P[j] = (P[j] + (j * P[j-1])%mod)%mod;
		}
	}
	return P[k];
}
int main(){
	int n, k, T; cin >> T;
	while (T--){
		cin >> n >> k;
		cout << nPk(n, k) << endl;
	}
}
