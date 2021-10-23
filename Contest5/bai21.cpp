#include<bits/stdc++.h>
typedef long long ll;
ll const mod = 1e9 + 7;
using namespace std;
void solve(ll arr[], int n, int k){
	int F[k+1]; 
    memset(F, 0, sizeof(F)); 
    F[0] = 1; 
    for (int i = 1; i <= k; i++) 
        for (int j = 0; j < n; j++){
        	if (i >= arr[j]) 
                F[i] = (F[i]%mod + F[i - arr[j]]%mod)%mod; 
		}
	for (int i = 1; i <= k; i++) 
		cout << F[i] << endl;
    cout << F[k] << endl;  
}
int main(){
	int T; cin >> T;
	while (T--){
		ll n, k; cin >> n >> k;
		ll *arr = new ll[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		solve(arr, n, k);
		delete arr;
	}
}
