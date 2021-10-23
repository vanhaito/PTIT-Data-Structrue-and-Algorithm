#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
long long solve(string str, ll k){
	ll l = str.length();
	if (k >= l)
		return 0;
	ll freq[26] = {0};
	for (ll i = 0; i < l; i++)
		freq[str[i]-'A']++;
	priority_queue<int> q;
	for (ll i = 0; i < 26; i++)
		q.push(freq[i]);
	while (k--){
		ll tmp = q.top();
		q.pop();
		tmp = tmp - 1;
		q.push(tmp);
	}
	ll res = 0;
	while (!q.empty()){
		ll tmp = q.top();
		q.pop();
		res = res + tmp*tmp;
	}
	return res;
}
int main(){
	int t; cin >> t;
	while (t--){
		ll k; cin >> k;
		string str; cin >> str;
		cout << solve(str, k) << endl;
	}
}
