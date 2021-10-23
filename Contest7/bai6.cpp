#include<bits/stdc++.h>
using namespace std;
bool solve(string &str){
	stack<char> s;
	for (int i=0; i<str.length(); i++){
		if (str[i] == ')'){
			char top = s.top();
			s.pop();
			bool flag = true;
			while (top != '('){
				if (top=='+' || top=='-' || top=='*' || top=='/')
					flag = false;
				top = s.top();
				s.pop();
			}
			if (flag == true)
				return true;
		}
		else
			s.push(str[i]);
	}
	return false;
}
int main(){
	int T; cin >> T;
	while (T--){
		string s; cin >> s;
		bool ans = solve(s);
		if (ans == true) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
