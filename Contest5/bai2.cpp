#include<bits/stdc++.h>
using namespace std;
int F[1005];
int longestIncrease(int arr[], int n){
	int dmax = 0;
	arr[0] = 0;
	F[0] = 0;
	for (int i = 1; i <= n; i++){
		F[i] = 1;
		for (int j = i-1; j >= 1; j--){
			if (arr[i] > arr[j]){
				F[i] = max(F[i], F[j]+1);
				if (F[i] > dmax) dmax = F[i];
			}
		}
	}
	return dmax;
}
int main(){
	int arr[1005], n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cout << longestIncrease(arr, n);
}
