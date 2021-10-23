#include<bits/stdc++.h>																																																																																															#include<bits/stdc++.h>
using namespace std;
void solve(int arr[], int n){
	int ans = 0;
	sort(arr, arr+n);
	for (int i=0; i<n-1; i++){
		if (arr[i]!=arr[i+1] && arr[i]!=arr[i+1]-1)
			ans += arr[i+1]-arr[i]-1;
	}
	cout << ans << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		int *arr = new int[n];
		for (int i=0; i<n; i++) cin >> arr[i];
		solve(arr, n);
	}
}
