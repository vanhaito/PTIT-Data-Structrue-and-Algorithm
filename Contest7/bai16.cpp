#include<bits/stdc++.h>
using namespace std;
bool isOperator(char c){
	if (c == '*' || c == '/' || c == '+' || c == '-')
		return true;
	return false;
}
void solve(string str){
	stack<int> s;
	for (int i = 0; i < str.length(); i++){
		if (isOperator(str[i])){
			int x1 = s.top(); s.pop();
			int x2 = s.top(); s.pop();
			switch (str[i]){
				case '+': s.push(x2 + x1); break;
				case '-': s.push(x2 - x1); break;
				case '*': s.push(x2 * x1); break;
				case '/': s.push(x2 / x1); break;
			}
		}
		else{
			s.push(str[i] - '0');
		}
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
