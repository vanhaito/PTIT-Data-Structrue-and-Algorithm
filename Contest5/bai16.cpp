#include<bits/stdc++.h>
using namespace std;
void solve(int arr[], int n){
	int maxSum = 0;
	int tmp[n];
	for (int i = 0; i < n; i++)
		tmp[i] = arr[i];
	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && tmp[i] < tmp[j] + arr[i])
				tmp[i] = tmp[j] + arr[i];
	}
	for (int i = 0; i < n; i++)
		if (maxSum < tmp[i])
			maxSum = tmp[i];
	cout << maxSum << endl;
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
