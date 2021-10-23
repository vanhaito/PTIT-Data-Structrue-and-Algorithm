#include<bits/stdc++.h>
using namespace std;

void result(int A[], int n){
	cout<<"[";
	for(int i = 0; i < n; i++){
		if (i == n-1) cout << A[i] <<"]";
		else cout << A[i] << " ";
	}
}

void recursion(int A[], int n){
	if (n < 1) return;
	else {
		int tmp[n-1];
		for(int i = 0; i < n-1; i++){
			int x = A[i] + A[i+1];
			tmp[i] = x;
		}
		recursion(tmp, n-1);
		result(A, n);
	}
}

int main(){
	int t; cin>>t;
	while(t--){
		int n, A[100];
		cin>>n;
		for(int i = 0; i < n; i++){
			cin >> A[i];
		}
		recursion(A, n);
		cout<<endl;
	}
}
