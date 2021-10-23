#include<bits/stdc++.h>
using namespace std;
int lookup[1005][1005];
int longestSubstring(string s1, string s2){
	int maxlen = 0;	
	int m = s1.length(), n = s2.length();
	memset(lookup, 0, sizeof(lookup));
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			if (s1[i - 1] == s2[j - 1])
				lookup[i][j] = lookup[i - 1][j - 1] + 1;
			else 
				lookup[i][j] = max(lookup[i-1][j], lookup[i][j-1]);
				
			if (lookup[i][j] > maxlen)
				maxlen = lookup[i][j];
		}
	}
	return maxlen;
}
int main(){
	int T; cin >> T;
	while (T--){
		string s1, s2;
		cin >> s1 >> s2;
		cout << longestSubstring(s1, s2) << endl;
	}
}
