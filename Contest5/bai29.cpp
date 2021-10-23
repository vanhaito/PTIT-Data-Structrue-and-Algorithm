#include<bits/stdc++.h>
using namespace std;
void solve(char *ch){
	int n = strlen(ch);
	int F[n+1];
	F[0] = 1;
	F[1] = 1;
	if (ch[0] == '0'){
		cout << 0 << endl;
		return;
	}
	for (int i = 2; i <= n; i++){
		F[i] = 0;
		if (ch[i-1] > '0')
			F[i] = F[i-1];
		if (ch[i-2] == '1' || ch[i-2] == '2' && ch[i-1] < '7')
			F[i] += F[i-2];
	}
	cout << F[n] << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		char ch[45];
		cin >> ch;
		solve(ch);
	}
}
