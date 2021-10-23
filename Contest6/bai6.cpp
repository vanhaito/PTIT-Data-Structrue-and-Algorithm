#include<bits/stdc++.h>
using namespace std;
void solve(int arr[], int n){
	int low = 0;
	int mid = 0;
	int high = n-1;
	while (mid <= high){
		if (arr[mid] == 0){
			swap(arr[mid], arr[low]);
			mid++;
			low++;
		}
		else if (arr[mid] == 1){
			mid++;
		}
		else{
			swap(arr[mid], arr[high]);
			high--;
		}
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
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

