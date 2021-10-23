#include<bits/stdc++.h>
using namespace std;
bool isOperator(char c){
	if (c == '*' || c == '/' || c == '+' || c == '-')
		return true;
	return false;
}
void solve(string str){
	stack<string> s;
	for (int i = str.length()-1; i >= 0; i--){
		if (isOperator(str[i])){
			string str1 = s.top(); s.pop();
			string str2 = s.top(); s.pop();
			string tmp = "(" + str1 + str[i] + str2 + ")";
			s.push(tmp);
		}
		else
			s.push(string(1, str[i]));
	}
	cout << s.top() << endl;
}
int main() { 
    int t; cin >> t;
    while (t--){
    	string s; cin >> s;
    	solve(s);
	}
} 
