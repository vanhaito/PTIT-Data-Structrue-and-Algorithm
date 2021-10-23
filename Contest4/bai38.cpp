#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void mergeArr(ll A[], ll B[], ll m, ll n, ll C[]){
	ll i = 1, j = 1, k = 1;
	while (i <= m && j <= n){
		if (A[i] < B[j])
			C[k++] = A[i++];
		else
			C[k++] = B[j++];
	}
	while (i <= m)
		C[k++] = A[i++];
	while (j <= n)
		C[k++] = B[j++];
}
int main(){
	ll *A, *B, *C, m , n, k, T; cin >> T;
	while (T--){
		cin >> m >> n >> k;
		A= new ll[m+5]; B = new ll[n+5]; C = new ll[m+n+10];
		for (ll i = 1; i <= m; i++) cin >> A[i];
		for (ll i = 1; i <= n; i++) cin >> B[i];
		mergeArr(A, B, m, n, C);
        cout << C[k] << endl; 
		delete A; delete B; delete C;
	}
}
