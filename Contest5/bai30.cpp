#include<bits/stdc++.h>
using namespace std;
void solve(int n){
	int F[n+1];
	F[0] = 0;
	F[1] = 1;
	F[2] = 2;
	F[3] = 3;
	for (int i = 4; i <= n; i++){
		F[i] = i;
		for (int j = 2; j <= ceil(sqrt(i)); j++){
			int tmp = j*j;
			if (tmp > i)
				break;
			else
				F[i] = min(F[i], 1 + F[i-tmp]);
		}
	}
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
