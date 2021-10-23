#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high){
	int p = arr[high];
	int i = low-1;
	for (int j = low; j <= high-1; j++){
		if (arr[j] < p){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	return i+1;
}
void quicksort(int arr[], int low, int high){
	if (low < high){
		int k =partition(arr, low, high);
		quicksort(arr, low, k-1);
		quicksort(arr, k+1, high);
	}
}
int main(){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		int *arr = new int[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		quicksort(arr, 0, n-1);
		for (int i=0; i<n; i++)
			cout << arr[i] << " ";
		cout << endl;
		delete arr;
	}
}
