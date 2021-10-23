#include<bits/stdc++.h>
using namespace std;
void printArr(int arr[],int  n){
	for (int i=1; i<=n; i++){
		if (arr[i] == 0) cout << "A";
		else cout << "B";
	}	
	cout << " ";
}
int solve(int arr[], int n){
	int i = n;
	while (i>0 && arr[i]){
		arr[i] = 0;
		i--;
	}
	if (i > 0){
		arr[i] = 1;
	}
	else
	    return -1;
}
int main(){
	int T; cin >> T;
	while (T--){
		int arr[15], n; cin >> n;
		for (int i=1; i<=n; i++) arr[i] = 0;
		while (true){
			printArr(arr, n);
			int tmp = solve(arr, n);
			if (tmp == -1) break;
		}
		cout << endl;
	}
}
