#include<bits/stdc++.h>
typedef long long ll;
ll const mod = 1e9 + 7;
using namespace std;
ll power(int n, int k){
	ll tmp;
	if (k == 0)
		return 1;
	tmp = power(n % mod, k / 2) % mod;
	if (k % 2 == 0)
		return ((tmp % mod) * (tmp % mod)) % mod;
	else
		return ((n % mod) * (((tmp % mod) * (tmp % mod)) % mod) % mod) % mod;
}
int main(){
	int n, k , T; cin >> T;
	while (T--){
		cin >> n >> k;
		cout << power(n, k) << endl;
	}
}
