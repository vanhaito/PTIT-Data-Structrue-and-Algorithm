#include<bits/stdc++.h>
using namespace std;
void printArr(int arr[], int  k){
	for (int i=1; i<=k; i++)
		cout << arr[i];
	cout << " ";
}
int solve(int arr[], int n, int k){
	int i = k;
	while (i>0 && arr[i]==n-k+i)
		i--;
	if (i > 0){
		arr[i] = arr[i]+1;
		for (int j=i+1; j<=k;j++)
			arr[j] = arr[i]+j-i;
	}
	else{
		return -1;		
	}
}
int main(){
	int T; cin >> T;
	while (T--){
		int *arr, n, k; cin >> n >> k;
		arr = new int[n];
		for (int i=1; i<=k; i++)
			arr[i] = i;
		while (true){
			printArr(arr, k);
			int tmp = solve(arr, n, k);
			if (tmp == -1) break;
		}
		cout << endl;
	}
}
