#include<bits/stdc++.h>
using namespace std;
bool solution(int arr[], int n){
	int b[n];
	copy(arr, arr+n, b);
	sort(b, b+n);
	for(int i = 0; i < n; i++){
		if (!(arr[i] == b[i]) && !(arr[n-i-1] == b[i]))
			return false;
	}
	return true;
}
int main(){
	int *arr, n, t; cin >> t;
	while(t--){
		cin >> n; arr = new int[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		if (solution(arr, n)) cout << "Yes" << endl;
		else cout << "No" << endl;
		delete arr;
	}
}
