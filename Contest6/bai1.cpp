#include<bits/stdc++.h>
using namespace std;
void solve(int arr[], int n){
	sort(arr, arr+n, greater<int>());
	int tmp[n];
	int index = 0;
	for (int i = 0, j = n-1; i <= n/2 || j > n/2; i++, j--){
		tmp[index] = arr[i];
		index++;
		tmp[index] = arr[j];
		index++;
	}
	for (int i = 0; i < n; i++)
		arr[i] = tmp[i];
}
int main(){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		int *arr = new int[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		solve(arr, n);
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
		delete arr;
	}
}
