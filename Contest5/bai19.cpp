#include<bits/stdc++.h>
using namespace std;
void solve(int n, int insert, int remove, int copy){
	int F[n+1];
	memset(F, 0, sizeof(F));
	F[1] = insert;
	for (int i = 2; i <= n; i++){
		if (i%2 == 0)
			F[i] = min(F[i-1] + insert, F[i/2] + copy);
		else
			F[i] = min(F[i-1] + insert, F[(i+1)/2] + copy + remove);
	}
	cout << F[n] << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		int n, insert, remove, copy;
		cin >> n >> insert >> remove >> copy;
		solve(n, insert, remove, copy);
	}
}
