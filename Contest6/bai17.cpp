#include <bits/stdc++.h> 
using namespace std; 
long long solve(long long arr1[], long long arr2[], int n1,  int n2){  
    sort(arr1, arr1 + n1); 
    sort(arr2, arr2 + n2);  
    return arr1[n1 - 1] * arr2[0]; 
} 
  
int main(){ 
    int T; cin >> T;
    while (T--){
    	int n1, n2; cin >> n1 >> n2;
    	long long *arr1 = new long long[n1], *arr2 = new long long[n2];
    	for (int i = 0; i < n1; i++)
    		cin >> arr1[i];
    	for (int j = 0; j < n2; j++)
    		cin >> arr2[j];
    	cout << solve(arr1, arr2, n1, n2) << endl;
    	delete arr1; delete arr2;
	}
} 
