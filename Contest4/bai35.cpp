#include<bits/stdc++.h>
using namespace std;
int maxLR(int A[], int m, int l, int r){
	int sum = 0;
	int leftSum = INT_MIN;
	for (int i = m; i >= l; i--){
		sum += A[i];
		if (sum > leftSum)
			leftSum = sum;
	}
	sum = 0;
	int rightSum = INT_MIN;
	for (int i = m + 1; i <= r; i++){
		sum += A[i];
		if (sum > rightSum)
			rightSum = sum;
	}
	return leftSum + rightSum;
}
int maxGlobal(int A[], int l, int r){
	if (l == r)
		return A[l];
	int m = (l + r) / 2; 
	return max(max(maxGlobal(A, l, m), maxGlobal(A, m + 1, r)), maxLR(A, m, l, r));
}
int main(){
	int *A, n, T; cin >> T;
	while (T--){
		cin >> n; A= new int[n];
		for (int i = 0; i , i < n; i++) cin >> A[i];
		cout << maxGlobal(A, 0, n-1) << endl;
	}
}
