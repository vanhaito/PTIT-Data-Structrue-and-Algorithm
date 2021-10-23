#include<bits/stdc++.h>
typedef long long ll;
ll const mod = 1e9 + 7;
using namespace std;
ll nCk(int n, int k){
	if (k > n - k)
		k = n - k;
	ll C[k+1];
	memset(C, 0, sizeof(C));
	C[0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = min(i, k); j > 0; j--)
			C[j] = (C[j] +C[j-1]) % mod;
	}
	return C[k];
}
int main(){
	int n, k, T; cin >> T;
	while (T--){
		cin >> n >> k;
		cout << nCk(n, k) << endl;
	}
}
