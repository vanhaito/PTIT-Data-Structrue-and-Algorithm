#include<bits/stdc++.h>
using namespace std;
void solve(int arr[], int n){
	int total = n*(n+1)/2;
	for (int i=0; i<n-1; i++)
		total -= arr[i];
	cout << total << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		int *arr = new int[n];
		for (int i=0; i<n-1; i++) cin >> arr[i];
		solve(arr, n);
	}
}
