#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve(int n){
	ll F[n+1];
	F[0] = 1;
	F[1] = 1;
	F[2] = 2;
	for (int i = 3; i <= n; i++)
		F[i] = F[i-1] + F[i-2] + F[i-3];
	cout << F[n] << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		int n;
		cin >> n;
		solve(n);
	}
}
