#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll mod(string str, ll n){
	ll r = 0;
	for (ll i = 0; i < str.length(); i++){
		r = r*10 + (str[i]-'0');
		r %= n;
	}
	return r;
}
void solve(long long n){
	queue<string> q;
	q.push("1");
	while (!q.empty()){
		string str = q.front();
		q.pop();
		long long r = mod(str, n);
		if (r == 0){
			cout << str << endl;
			break;
		}
		q.push(str+"0");
		q.push(str+"1");
	}
}
int main(){
	int t; cin >> t;
	while (t--){
		long long n; cin >> n;
		solve(n);
	}
}

