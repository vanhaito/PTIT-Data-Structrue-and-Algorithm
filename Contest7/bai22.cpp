#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve(ll arr[], int n){
	stack<int> s;
	ll res = 0, tp, area;
	int i = 0;
	while (i < n){
		if (s.empty() || arr[s.top()] < arr[i])
			s.push(i++);
		else{
			tp = s.top(); s.pop();
			area = arr[tp] * (s.empty()? i: i-s.top()-1);
			if (area > res)
				res = area;
		}
	}
	while (!s.empty()){
		tp = s.top(); s.pop();
		area = arr[tp] * (s.empty()? i: i-s.top()-1);
		if (area > res)
			res = area;
	}
	cout << res << endl;
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
