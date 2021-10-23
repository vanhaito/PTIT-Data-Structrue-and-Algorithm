#include<bits/stdc++.h>
using namespace std;
void solve(int arr[], int n, int k){
	sort(arr, arr+n, greater<int>());
	for (int i = 0; i < k; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		int n, k; cin >> n >> k;
		int *arr = new int[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		solve(arr, n, k);
		delete arr;
	}
}
