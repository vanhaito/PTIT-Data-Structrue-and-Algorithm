#include<bits/stdc++.h> 
typedef long long ll;
ll const mod = 123456789;
using namespace std;
ll countSequence(ll n){
	if (n == 0) return 1;
	if (n == 1) return 2;
	ll tmp = countSequence(n/2);
	if (n%2 == 0) return (tmp%mod * tmp%mod) % mod;
	return (2 * ((tmp%mod * tmp%mod)%mod)) % mod;
}
int main(){
	ll n , T; cin >> T;
	while (T--){
		cin >> n;
		cout << countSequence(n-1) << endl;
	}
}
