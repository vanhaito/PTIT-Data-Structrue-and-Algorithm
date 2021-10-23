#include<bits/stdc++.h>
using namespace std;
void solve(int arr[], int n, int sum){
	int ans = 0;
	sort(arr, arr+n);
	int i = 0, j = n-1;
	while (i < j){
		if (arr[i]+arr[j] < sum)
			i++;
		else if (arr[i]+arr[j] > sum)
			j--;
		else{
			int x = arr[i], xx = i;
			while (i<j && arr[i] == x) i++;
			int y = arr[j], yy = j;
			while (j>=i && arr[j] == y) j--;
			if (x == y){
				int tmp = i-xx+yy-j-1;
				ans += (tmp*(tmp+1))/2;
			}
			else
				ans += (i-xx)*(yy-j);
		}
	}
	cout << ans << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		int n, sum; cin >> n >> sum;
		int arr[105];
		for (int i = 0; i < n; i++) cin >> arr[i];
		solve(arr, n, sum);
	}
}
