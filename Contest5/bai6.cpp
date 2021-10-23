#include<bits/stdc++.h>
using namespace std;
int longestSymSubstr(string s){
	int n = s.size();
	bool f[n][n];
	memset(f, 0, sizeof(f));
	int maxlen = 1;
	for (int i = 0; i < n; i++)
		f[i][i] = true;
	for (int i = 0; i < n-1; i++){
		if (s[i] == s[i+1]){
			f[i][i+1] = true;
			maxlen = 2;
		}
	}
	for (int k = 3; k <= n; k++){
		for (int i = 0; i < n-k+1; i++){
			int j = i+k-1;
			if (f[i+1][j-1] && s[i] == s[j]){
				f[i][j] = true;
				if (k > maxlen)
					maxlen = k;
			}
		}
	}
	return maxlen;
}
int main(){
	int T; cin >> T;
	while (T--){
		string s; cin >> s;
		cout << longestSymSubstr(s) << endl;
	}
}
