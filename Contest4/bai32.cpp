#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll merge(ll arr[], ll tmp[], ll left, ll mid, ll high){
	ll i, j, k; // i and j are index for left&right sub array, k is index for sorted array
	ll count = 0;
	i = left; j = mid; k = left;
	while (i <= mid-1 && j <= high){
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else{
			tmp[k++] = arr[j++];	
			count += mid - i; // find how many convertion is performed
		}
	}
	// add remainning items
	while (i <= mid-1) tmp[k++] = arr[i++];
	while (j <= high) tmp[k++] = arr[j++];
	// store array
	for (ll i = left; i <= high; i++)
		arr[i] = tmp[i];
	return count;
}
ll mergeSort(ll arr[], ll tmp[], ll left, ll high){
	ll count = 0;
	if (left < high){
		ll mid = (high + left) / 2;
		count += mergeSort(arr, tmp, left, mid); // left sub array
		count += mergeSort(arr, tmp, mid+1, high); // right sub array
		count += merge(arr, tmp, left, mid+1, high); // merge 2 sub arrays
	}
	return count;
}
int main(){
	ll n, T; cin >> T;
	while (T--){
		cin >> n;
		ll *arr = new ll[n+5], *tmp = new ll[n+5];
		for (ll i = 0; i < n; i++) cin >> arr[i];
		ll ans = mergeSort(arr, tmp, 0, n-1);
		cout << ans << endl;
		delete arr; delete tmp;
	}
}
