#include<bits/stdc++.h>
using namespace std;
void solve(int arr[], int n){
	int F[n], max = 0;
	for (int i = 0; i < n; i++)
		F[i] = 1;
	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++)
			if (arr[i] >= arr[j] && F[i] < F[j] +1)
				F[i] = F[j] + 1;
	}			
	for (int i = 0; i < n; i++)
		if (max <  F[i])
			max = F[i];
	cout << n-max << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		int *arr,n; cin >> n;
		arr = new int[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		solve (arr, n);
		delete arr;
	}
}
