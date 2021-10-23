#include<bits/stdc++.h>
using namespace std;
void subarraySum(int arr[], int n, int sum){
	sort(arr, arr+n);
	int currSum = arr[0], index = 0;
	for (int i = 1; i <= n; i++){
		while (currSum > sum && index < i-1){
			currSum -= arr[index];
			index++;
		}
		if (currSum == sum){
			cout << "YES" << endl;
			return;
		}
		if (i < n)
			currSum += arr[i];
	}
	cout << "NO" << endl;
}
int main(){
	int arr[205], n, sum, T; cin >> T;
	while (T--){
		cin >> n >> sum;
		for (int i = 0; i < n; i++) cin >> arr[i];
		subarraySum(arr, n, sum);
	}
}

