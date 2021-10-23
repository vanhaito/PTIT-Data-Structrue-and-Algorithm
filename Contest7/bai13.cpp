#include<bits/stdc++.h>
using namespace std; 
bool isOperator(char c){
	if (c == '*' || c == '/' || c == '+' || c == '-')
		return true;
	return false;
}
void solve(string str) { 
  stack<string> s; 
  int length = str.size(); 
  for (int i = length - 1; i >= 0; i--) { 
    if (isOperator(str[i])) { 
      string op1 = s.top(); s.pop(); 
      string op2 = s.top(); s.pop(); 
      string temp = op1 + op2 + str[i];  
      s.push(temp); 
    } 
    else { 
      s.push(string(1, str[i])); 
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
