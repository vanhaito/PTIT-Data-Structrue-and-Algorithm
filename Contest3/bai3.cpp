#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MAX = 1e9 + 7;
ll maxSum(ll arr[], int n){
	sort(arr, arr + n);
	ll sum = 0;
	for (int i = 0; i < n; i++){
		sum += arr[i] * i;
		sum %= MAX;
	}
	return sum;
}
int main(){
	int t, n;
	ll *arr;
	cin >> t;
	while(t--){
		cin >> n;
		arr = new ll[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cout << maxSum(arr, n) << endl;
		delete arr;
	}
}
