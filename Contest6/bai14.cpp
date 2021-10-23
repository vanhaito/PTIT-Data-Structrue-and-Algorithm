#include<bits/stdc++.h>
using namespace std;
bool prime[1000006];
void sieve(){
	prime[0] = prime[1] = false;
	for (int i=2; i<=1000005; i++)
		prime[i] = true;
	for (int i=2; i*i<=1000005; i++){
		if(prime[i]){
			for (int j=i*i; j<=1000005; j+=i)
				prime[j]=false;
		}
	}	
}
void solve(int n){
	for (int i=0; i<n; i++){
		if (prime[i] && prime[n-i]){
			cout << i << " " << n-i << endl;
			return;
		}
	}
	cout << "-1" << endl;
}
int main(){
	sieve();
	int T; cin >> T;
	while (T--){
		int n; cin >> n;
		solve(n);	
	}
}
