#include<bits/stdc++.h>
using namespace std;
void solve(int arr[], int n){
	int first, second;
	first = second = INT_MAX;
	for (int i=0; i<n; i++){
		if (arr[i] < first){
			second = first;
			first = arr[i];
		}
		if (arr[i]<second && arr[i]!=first)
			second = arr[i];
	}
	if (second == INT_MAX) cout << "-1" << endl;
	else cout << first << " " << second << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		int *arr = new int[n];
		for (int i=0; i<n; i++) cin >> arr[i];
		solve(arr, n);
	}
}
