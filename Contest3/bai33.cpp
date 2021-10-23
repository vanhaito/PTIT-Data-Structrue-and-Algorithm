#include<bits/stdc++.h>
typedef long long ll;
ll const mod = 1e9 + 7;
using namespace std;
ll reversePower(ll n){
	ll reverse = 0;
	ll nn = n;
	while (n > 0){
		ll k = n % 10;
		reverse = reverse*10 + k;
		n = n  / 10;
	}
	ll res = 1;
	nn = nn % mod;
	while (reverse){
		if (reverse & 1)
			res = ((res % mod) * (nn % mod)) % mod;
		nn = ((nn % mod) * (nn % mod)) % mod;
		reverse = reverse >> 1;
	}
	return res % mod;
}
int main(){
	ll n, T; cin >> T;
	while (T--){
		cin >> n;
		cout << reversePower(n) << endl;
	}
}
