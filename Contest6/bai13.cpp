#include<bits/stdc++.h>
using namespace std;
int solve(int arr[], int n, int x){
	int *low = lower_bound(arr, arr+n, x);
	if (low == (arr+n) || *low != x)
		return -1;
	int *high = upper_bound(arr, arr+n, x);
	return high-low;
}
int main(){
	int T; cin >> T;
	while (T--){
		int n, x; cin >> n >> x;
		int *arr = new int[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		cout << solve(arr, n, x) << endl;
		delete arr;
	}
}
