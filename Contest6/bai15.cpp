#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int tmp[], int left, int mid, int high){
	int i, j, k;
    i=left, j=mid, k=left;
	while (i<mid && j<=high){
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	while (i<mid) tmp[k++] = arr[i++];
	while (j<=high) tmp[k++] = arr[j++];
	for (int i=left; i<=high; i++)
		arr[i] = tmp[i];
}
void mergesort(int arr[], int tmp[], int left, int high){
	if (left<high){
		int mid = (left+high)/2;
		mergesort(arr, tmp, left, mid);
		mergesort(arr, tmp, mid+1, high);
		merge(arr, tmp, left, mid+1, high);
	}
}
int main(){
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		int *arr = new int[n], *tmp = new int[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		mergesort(arr, tmp, 0, n-1);
		for (int i=0; i<n; i++)
			cout << arr[i] << " ";
		cout << endl;
		delete arr; delete tmp;
	}
}
