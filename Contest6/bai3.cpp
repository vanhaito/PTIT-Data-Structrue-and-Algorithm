#include<bits/stdc++.h>
using namespace std;
void solve(int arr[], int n){
	pair<int, int> P[n];
	for (int i = 0; i < n; i++){
		P[i].first = arr[i];
		P[i].second = i;
	}
	sort(P, P+n);
	bool used[n];
	memset(used, false, sizeof(used));
	int ans = 0;
	for (int i = 0; i < n; i++){
		if (used[i] || P[i].second == i)	
			continue;
		int c = 0;
		int j = i;
		while (!used[j]){
			used[j] = true;
			j = P[j].second;
			c++;
		}
		if (c > 0)
			ans += c - 1;
	}
	cout << ans << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		int *arr = new int[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		solve(arr, n);
		delete arr;
	}
}
