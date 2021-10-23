#include<bits/stdc++.h>
using namespace std;
void solve(string s){
	int i = s.length()-1;
	while (i >= 0){
		if (s[i] == '0'){
			s[i] = '1';
			break;
		}
		else
			s[i] = '0';
		i--;
	}
	cout << s << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		string s; cin >> s;
		solve(s);
	}
}
