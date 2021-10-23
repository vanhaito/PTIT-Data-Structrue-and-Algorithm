#include<bits/stdc++.h>
using namespace std;
int firstZero(int A[], int l, int h){
	if (l <= h){
		int m = l + (h - l) / 2;
		if (( m == 0 || A[m-1] == 0) && A[m] == 1) 
			return m;
		if (A[m] == 0)
			return firstZero(A, m+1, h);
		else
			return firstZero(A, l, m-1);
	}
	return -1;
}
int countZeros(int A[], int n){
	int first = firstZero(A, 0, n-1);
	if (first == - 1)
		return n;
	return first;
}
int main(){
	int *A;
	int n, T; cin >> T;
	while (T--){
		cin >> n; A= new int[n];
		for (int i = 0; i < n; i++) cin >> A[i];
		cout << countZeros(A, n) << endl;
	}
}

