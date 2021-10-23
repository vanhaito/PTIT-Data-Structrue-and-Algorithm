#include<bits/stdc++.h>
using namespace std;
int main(){
	int T; cin >> T;
	while (T--){
		int n, k; cin >> n >> k;
		int *arr = new int[n];
		for (int i=0; i<n; i++) cin >> arr[i];
		sort(arr, arr+n);
		long long ans = 0;
		for (int i=0; i<n-1; i++){
			int tmp = lower_bound(arr+i, arr+n, arr[i]+k)-arr-1;
			ans += tmp-i;
		}
		cout << ans << endl;
	}
}
