#include<bits/stdc++.h>
typedef long long ll;
ll const mod = 1e9 + 7;
using namespace std;
ll power(ll n, ll k){
	if (k == 0) return 1;
	if (k == 1) return n%mod;
	ll x = power(n, k/2);
	if (k%2 == 0) return x*x%mod;
	return n*(x*x%mod)%mod;
}
int main(){
	ll n, k, T; cin >> T;
	while (T--){
		cin >> n;
		ll m = n;
        k = 0;
        while(m){
            k = 10*k + m%10;
            m /= 10;
        }
		cout << power(n, k) << endl;
	}
}
