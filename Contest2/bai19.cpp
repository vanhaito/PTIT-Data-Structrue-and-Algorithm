#include<bits/stdc++.h>
using namespace std;

void in(int A[], int n) {
	cout<<"[";
	for (int i = 0; i < n; i++) {
		if (i == n-1) cout<<A[i]<<"]";
		else cout << A[i] << " ";
	}
	cout << endl;
}
void dequy(int A[], int n) {
	if (n < 1) return;
	else {
		int temp[n-1];
		for (int i = 0; i <n-1; i++) {
			int x = A[i] + A[i + 1];
			temp[i] = x;
		}
		in(A, n);
		dequy(temp, n - 1);
	}
}
int main() {
	int t; cin>>t;
	while(t--){
		int n, A[100];
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		dequy(A, n);
	}
}
