#include<bits/stdc++.h>
using namespace std;
void solve(int arr[], int n, int k){
	int i = k;
	while (i>0 && arr[i]==n-k+i)
		i--;
	if (i > 0){
		arr[i] = arr[i]+1;
		for (int j=i+1; j<=k;j++)
			arr[j] = arr[i]+j-i;
		return;
	}
	else{
		for (int j=1; j<=k; j++)
			arr[j] = j;
		return;		
	}
}
int main(){
	int T; cin >> T;
	while (T--){
		int *arr, n, k; cin >> n >> k;
		arr = new int[n];
		for (int i=1; i<=k; i++) cin >> arr[i];
		solve(arr, n, k);
		for (int i=1; i<=k; i++)
			cout << arr[i] << " ";
		cout << endl;
		delete arr;
	}
}
