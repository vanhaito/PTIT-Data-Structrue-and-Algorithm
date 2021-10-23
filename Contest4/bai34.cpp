#include<bits/stdc++.h>
using namespace std;
int *multi(int A[], int B[], int m, int n){
	int *res = new int[m + n - 1];
	for (int i = 0; i<m+n-1; i++) 
     	res[i] = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			res[i+j] += A[i] * B[j];
	return res;
}
void result(int poly[], int n){
	for (int i = 0; i < n; i++)
		cout << poly[i] << " ";
	cout << endl;
}
int main(){
	int A[100], B[100], m, n, T; cin >> T;
	while(T--){
		cin >> m >> n;
		for (int i = 0; i < m; i++)	cin >> A[i];
		for (int i = 0; i < n; i++)	cin >> B[i];
		int *res= multi(A, B, m, n);
		result(res, m+n-1);
	}
}
