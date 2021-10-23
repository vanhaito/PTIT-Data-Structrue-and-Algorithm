#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve(int arr[], int n){
	ll F[n], maxSum = 0;
	for (int i = 0; i < n; i++)
		F[i] = arr[i];
	F[2] += F[0];
	for (int i = 3; i < n; i++)	
		F[i] += max(F[i-3], F[i-2]);
	for (int i = 0; i < n; i++)
		if (maxSum < F[i])
			maxSum = F[i];
	cout << maxSum << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		int n, *arr; cin >> n;
		arr = new int[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		solve(arr, n);
	}
}
