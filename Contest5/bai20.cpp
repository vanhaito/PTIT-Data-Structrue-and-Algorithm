#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int toNum(char c){
	return (c - '0');
}
void solve(string s){
	ll n = s.size();
	ll F[n+1];
	F[0] = toNum(s[0]);
	ll res = F[0];
	for (ll i = 1; i < n; i++){
		int num = toNum(s[i]);
		F[i] = (i+1)*num + 10*F[i-1];
		res += F[i];
	}
	cout << res << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		string s; cin >> s;
		solve(s);
	}
}
