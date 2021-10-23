#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll count(ll x, ll Y[], ll n, ll F[]){
	if (x == 0) return 0;
	if (x == 1) return F[0];
	ll* index = upper_bound(Y, Y+n, x);
	ll c = (Y+n) - index;
	c += F[0] + F[1];
	if (x == 2)
		c -= F[3] + F[4];
	if (x == 3)
		c += F[2];
	return c;
}
void solve(ll X[], ll Y[], ll m, ll n){
	ll F[5] = {0};
	for (ll i = 0; i < n; i++)
		if(Y[i] < 5)
			F[Y[i]]++;
	sort(Y, Y+n);
	ll total = 0;
	for (ll i = 0; i < m; i++)
		total += count(X[i], Y, n, F);
	cout << total << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		ll m, n; cin >> m >> n;
		ll *X = new ll[m]; ll *Y = new ll[n];
		for (ll i = 0; i < m; i++) cin >> X[i];
		for (ll j = 0; j < n; j++) cin >> Y[j];
		solve(X, Y, m, n);
		delete X; delete Y;
	}
}
