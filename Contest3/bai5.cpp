#include<bits/stdc++.h>
using namespace std;
int maxDiff(int arr[], int n, int k){
	int s1 = 0, s2 = 0;
	int m, max_diff;
	for (int i = 0; i < n; i ++)
		 s1 += arr[i];
	sort(arr, arr+n, greater<int>());
	m = max(k, n-k);
	for (int i = 0; i < m; i++)
		s2 += arr[i];
	max_diff = s2 - (s1 -s2);
	return max_diff;
}
int main(){
	int arr[100], n, k ,t; cin >> t;
	while(t--){
		cin >> n >> k;
		for (int i = 0; i < n; i++)	cin >> arr[i];
		cout << maxDiff(arr, n, k) << endl;
	}
}
