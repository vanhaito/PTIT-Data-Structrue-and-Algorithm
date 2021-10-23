#include<bits/stdc++.h>
using namespace std;
int binarySearch(int A[], int l, int r, int k){
	if (l <= r){
		int mid = l + (r - l) / 2;
		if (A[mid] == k)
			return mid;
		if (A[mid] > k)
			return binarySearch(A, l , mid-1, k);
		return binarySearch(A, mid+1, r, k);
	}
	return -1;
}
int main(){
	int *A, n, k, T; cin >> T;
	while (T--){
		cin >> n >> k; A = new int[n];
		for (int i = 0; i < n; i++) cin >> A[i];
		int res = binarySearch(A, 0, n-1, k);
		if (res == -1)	cout << "-1" << endl;
		else cout << 1 << endl;
	}
}
