#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void merge(ll arr[], ll tmp[], ll left, ll mid, ll high){
	ll i, j, k;
	i = left; j = mid; k = left;
	while (i < mid && j <= high){
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}	
	while (i < mid) tmp[k++] = arr[i++];
	while (j <= high) tmp[k++] = arr[j++];
	for (ll i = left; i <= high; i++)
		arr[i] = tmp[i];
}
void mergeSort(ll arr[], ll tmp[], ll left, ll high){
	if (left < high){
		ll mid = (left + high) / 2;
		mergeSort(arr, tmp, left, mid);
		mergeSort(arr, tmp, mid+1, high);
		merge(arr, tmp, left, mid+1, high);
	}
}

int main(){
	ll n;
	cin >> n;
	ll *arr = new ll[n], *tmp = new ll[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	mergeSort(arr, tmp, 0, n-1); 
	for (ll i = 0; i < n; i++)
		cout << arr[i] << " "; 

}

