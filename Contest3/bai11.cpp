#include<bits/stdc++.h>
typedef long long ll;
ll mod = 1e9 + 7;
using namespace std;
ll minCost(ll arr[], ll n){
	priority_queue<ll, vector<ll>, greater<ll> > pq(arr, arr + n);
	ll res = 0;
	while(pq.size() > 1){
		ll first = pq.top();
		pq.pop();
		ll second = pq.top();
		pq.pop();
		res += (first + second) % mod;
		pq.push((first + second) % mod);
	}
	return res%mod;
}
int main(){
	ll n, *arr;
	cin >> n;
	arr = new ll[n];
	for (int i = 0 ; i < n; i++) cin >> arr[i];
	cout << minCost(arr, n);
	delete arr;
}
