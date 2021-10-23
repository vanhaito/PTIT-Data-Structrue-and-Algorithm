#include<bits/stdc++.h>
using namespace std;
void solve(int arr[], int n){
	int start = 1, end = n;
	for (start = 1; start <= n; start++)
		if (arr[start] > arr[start+1])
			break;
	for (end = n; start >= 1; end--)
		if (arr[end] < arr[end-1])
			break;
	int max = arr[start], min = arr[start];
	for (int i = start+1; i <= end; i++){
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	for (int i = 1; i < start; i++){
		if (arr[i] > min){
			start = i;
			break;
		}
	}
	for (int i = n; i >= end+1; i--){
		if (arr[i] < max){
			end = i;
			break;
		}
	}
	cout << start << " " << end << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		int *arr = new int[n+1];
		for (int i = 1; i <= n; i++) cin >> arr[i];
		solve(arr, n);
		delete arr;
	}
}
