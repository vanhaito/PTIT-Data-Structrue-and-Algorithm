#include<bits/stdc++.h>
using namespace std;
void solve(int arr[], int n, int x){
	for (int i = 1; i < n; i++){
		int k = abs(arr[i] - x);
		int j = i - 1;
		if (abs(arr[j]-x) > k){
			int tmp = arr[i];
			while (abs(arr[j]-x) > k && j >=0){
				arr[j+1] = arr[j];
				j--;
			}
			arr[j+1] = tmp;
		}
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		int n, x; cin >> n >> x;
		int *arr = new int[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		solve(arr, n, x);
		delete arr;
	}
}
