#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll Kthnumber(ll n, ll k){
	ll length = (1 << n) / 2 ;
	while (true){
		if (n == 1)
			return 1;
		if (length == k)
			return n;
		if (k > length)
			k = length - (k - length);
		n--;
		length /= 2;
	}
}
int main(){
	ll n, k, T; cin >> T;
	while (T--){
		cin >> n >> k;
		cout << Kthnumber(n, k) << endl;
	}
}
