#include<bits/stdc++.h>
using namespace std;
void Union(int arr1[], int arr2[], int m, int n){
	int i = 0;
	int j = 0;
	while (i<m && j<n){
		if (arr1[i] < arr2[j])
			cout << arr1[i++] << " ";
		else if(arr2[j] < arr1[i])
			cout << arr2[j++] << " ";
		else{
			cout << arr2[j++] << " ";
			i++;
		}
	}
	while (i < m) cout << arr1[i++] << " ";
	while (j < n) cout << arr2[j++] << " ";
	cout << endl;
}
void Intersection(int arr1[], int arr2[], int m, int n){
	int i = 0;
	int j = 0;
	while (i<m && j<n){
		if (arr1[i] < arr2[j])
			i++;
		else if(arr2[j] < arr1[i])
			j++;
		else{
			cout << arr2[j++] << " ";
			i++;
		}
	}
	cout << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		int m, n; cin >> m >> n;
		int *arr1 = new int[m]; int *arr2 = new int[n];
		for (int i = 0; i < m; i++) cin >> arr1[i];
		for (int j = 0; j < n; j++) cin >> arr2[j];
		Union(arr1, arr2, m, n);
		Intersection(arr1, arr2, m, n);
		delete arr1; delete arr2;
	}
}
