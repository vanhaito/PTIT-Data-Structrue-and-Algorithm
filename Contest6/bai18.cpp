#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve(int arr1[], int arr2[], int arr3[], int m, int n){
	int i=0, j=0, k=0;
	while (i<m && j<n){
		if (arr1[i] < arr2[j])
			arr3[k++] = arr1[i++];
		else
			arr3[k++] = arr2[j++];
	}
	while (i<m) arr3[k++] = arr1[i++];
	while (j<n) arr3[k++] = arr2[j++];
}
int main(){ 
    int T; cin >> T;
    while (T--){
    	int m, n; cin >> m >> n;
    	int *arr1 = new int[m], *arr2 = new int[n], *arr3 = new int[m+n+1];
    	for (int i = 0; i < m; i++)
    		cin >> arr1[i];
    	for (int j = 0; j < n; j++)
    		cin >> arr2[j];
    	solve(arr1, arr2, arr3, m, n);
    	sort(arr3, arr3+m+n);
    	for (int i = 0; i < m+n; i++)
			cout << arr3[i] << " ";
		cout << endl;
    	delete arr1; delete arr2; delete arr3;
	}
} 
