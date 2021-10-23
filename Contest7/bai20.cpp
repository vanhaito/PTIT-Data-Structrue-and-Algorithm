#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve(ll arr[], int n){
	stack<ll> s;
	ll ans[n];
	for (int i = n-1; i >= 0; i--){
		while (!s.empty() && arr[i] >= s.top())
			s.pop();
		if (s.empty())
			ans[i] = -1;
		else
			ans[i] = s.top();
		s.push(arr[i]);
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
}
int main(){
	int t; cin >> t ;
	while (t--){
		int n; cin >> n;
		ll *arr = new ll[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		solve(arr, n);
		delete arr;
	}
}
