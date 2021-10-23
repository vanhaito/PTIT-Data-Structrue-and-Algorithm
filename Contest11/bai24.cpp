#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while (t--){
		int n, *arr; cin >> n;
		arr = new int[n+1];
		for (int i=0; i<n; i++) cin >> arr[i];
		sort(arr, arr+n);
		int mid = (n-1)/2;
		int root = arr[mid];
		cout << root << endl;
	}
}
