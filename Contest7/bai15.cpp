#include<bits/stdc++.h>
using namespace std;
bool isOperator(char c){
	if (c == '*' || c == '/' || c == '+' || c == '-')
		return true;
	return false;
}
void solve(string str){
	stack<string> s;
	for (int i = 0; i < str.length(); i++){
		if (isOperator(str[i])){
			string str1 = s.top(); s.pop();
			string str2 = s.top(); s.pop();
			string tmp = "(" + str2 + str[i] + str1 + ")";
			s.push(tmp);
		}
		else
			s.push(string(1, str[i]));
	}
	cout << s.top() << endl;
}
int main() { 
    int t; cin >> t;
    cin.ignore();
    while (t--){
    	string s; getline(cin,s);
    	solve(s);
	}
} 
