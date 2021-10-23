#include<bits/stdc++.h>
using namespace std;
void solve(int arr[], int n){
	int min_l = 0;
	int min_r = 1;
	int min_sum = arr[0]+arr[1];
	for (int i=0; i<n-1; i++){
		for (int j=i+1; j<n; j++){
			int sum = arr[i] + arr[j];
			if (abs(min_sum) > abs(sum)){
				min_sum = sum;
				min_l = i;
				min_r = j;
			}
		}
	}
	cout << arr[min_l]+arr[min_r] << endl;
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
