#include<bits/stdc++.h>
typedef long long ll;
ll const mod = 1e9 + 7;
using namespace std;
void multiply(ll A[][100], ll B[][100], ll n){
	// Creating an matrix to store elements  
    // of the multiplication matrix 
	ll C[100][100];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			C[i][j] = 0;
			for (int k = 0 ; k < n; k++)
				C[i][j] = (C[i][j]+ A[i][k] * B[k][j]) % mod;
		}
	}
	// storing the multiplication result in A[][]
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			A[i][j] = C[i][j];
}
void power(ll A[][100], ll B[][100], ll n, ll k){
	// Divide and Conquer
	if ( k == 0 || k == 1) return;
	power(A, B, n, k/2);
	multiply(A, A, n);
	if (k%2 != 0) multiply(A, B, n); // k is odd	
}
int main(){
	ll n, k , T; cin >> T;
	while (T--){
		ll A[100][100], B[100][100];
		cin >> n >> k;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> A[i][j];
				B[i][j]= A[i][j];
			}
		}
		power(A, B, n, k);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << A[i][j] << " ";
			}
			cout<<endl;
		}
	}
}

