#include<bits/stdc++.h>
typedef long long ll;
ll const mod = 1e9 + 7;
using namespace std;
ll countWays(int n, int k){
	ll res[n];
	res[0] = 1; res[1] = 1;
	for (int i = 2; i < n; i++){
		res[i] = 0;
		for (int j = 1; j <= k && j <= i; j++)
			res[i] += res[i-j] % mod;
	}
	return res[n-1] % mod;
}
int main(){
	int T; cin >> T;
	while (T--){
		int n, k; cin >> n >>k;
		cout << countWays(n+1, k) << endl;
	}
}

