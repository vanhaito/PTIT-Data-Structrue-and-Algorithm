#include<bits/stdc++.h>
using namespace std;
void solve(int arr[], int n){
	int j = n-1;
	while (j>0 && arr[j]>arr[j+1])
		j--;
	if (j > 0){
		int k = n;
		while (arr[j] > arr[k])
			k--;
		swap(arr[j], arr[k]);
		int r = j+1;
		int s = n;
		while (r < s){
			swap(arr[r], arr[s]);
			r++; s--;
		}
		return;
	}
	else{
		for (int j=1; j<=n; j++)
			arr[j] = j;
		return;		
	}
}
int main(){
	int T; cin >> T;
	while (T--){
		int *arr, n; cin >> n;
		arr = new int[n+1];
		for (int i=1; i<=n; i++) cin >> arr[i];
		solve(arr, n);
		for (int i=1; i<=n; i++)
			cout << arr[i] << " ";
		cout << endl;
		delete arr;
	}
}
