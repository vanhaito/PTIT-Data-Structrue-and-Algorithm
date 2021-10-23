#include<bits/stdc++.h>
using namespace std;
int maxSumBitonic(int arr[], int n){
	int maxSum = INT_MIN;
	int A[n], B[n]; // tong long nhat cua day con tang dan va giam dan
	for (int i = 0; i < n; i++){
		A[i] = arr[i];
		B[i] = arr[i];
	}
	// tinh tu trai qua phai
	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++){
			if (arr[i] > arr[j] && A[i] < A[j] + arr[i])
				A[i] = A[j] + arr[i];
		}
	}
	// tinh tu phai qua trai
	for (int i = n-2; i >= 0; i--){
		for (int j = n-1; j > i; j--){
			if (arr[i] > arr[j] && B[i] < B[j] + arr[i])
				B[i] = B[j] + arr[i];
		}
	}
	for (int i = 0; i < n; i++)
		maxSum = max(maxSum, (A[i] + B[i] - arr[i]));
	return maxSum;
}
int main(){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		int *arr= new int[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		cout << maxSumBitonic(arr, n) << endl;
		delete arr;
	}
}
