#include<bits/stdc++.h> 
#define MAX 1000000007
typedef long long ll;
using namespace std; 
void multiply(ll F[2][2], ll M[2][2]) { 
  	ll x = (F[0][0]*M[0][0] + F[0][1]*M[1][0])%MAX;
	ll y = (F[0][0]*M[0][1] + F[0][1]*M[1][1])%MAX;  
  	ll z = (F[1][0]*M[0][0] + F[1][1]*M[1][0])%MAX; 
  	ll w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%MAX; 	    
  	F[0][0] = x;  F[0][1] = y;  F[1][0] = z;  F[1][1] = w; 
} 
void power(ll F[2][2], int n){   
  	if( n == 0 || n == 1) 
      return; 
  	ll M[2][2] = {{1,1},{1,0}}; 
  	power(F, n/2); 
  	multiply(F, F); 
    if (n % 2 != 0) 
    	multiply(F, M); 
} 
ll Fib(int n) { 
  	ll F[2][2] = {{1,1},{1,0}}; 
  	if (n == 0) 
      	return 0; 
  	power(F, n-1);   
  	return F[0][0]; 
} 
int main (void) { 
	int T, n; cin >> T;
	while (T--){
		cin >> n; cout << Fib(n) << endl;
	}
}  
