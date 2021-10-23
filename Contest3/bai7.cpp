#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll minValue(ll a[], ll b[], int n){
	sort(a, a+n);
	sort(b, b+n);
	ll res = 0;
	for (int i =0; i < n; i++){
		res += a[i] * b[n - i - 1];
	}
	return res;
}
int main(){
	ll *a, *b;
	int t, n; cin >> t;
	while(t--){
		cin >> n;
		a = new ll[n]; b = new ll[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		cout << minValue(a, b, n) << endl;
		delete a; delete b;
	}
}
