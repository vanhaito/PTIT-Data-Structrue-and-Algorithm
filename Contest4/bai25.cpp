#include<bits/stdc++.h>
typedef long long ll;
ll F[100];
using namespace std;
void init(){
	F[0] = 0;
	F[1] = 1;
	for (int i = 2; i <= 100; i++)
		F[i] = F[i-1] + F[i-2];
}
char Fib(int n, ll k){
	if (n == 1) return 'A';
	if (n == 2) return 'B';	
	if (k <= F[n-2]) return Fib(n-2, k);
	return Fib(n-1, k-F[n-2]);
}
int main(){
	init();
	ll k;
	int n, T; cin >> T;
	while (T--){
		cin >> n >> k;
		cout << Fib(n, k) << endl;
	}
}

