#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int prec(char c){
	if (c == '*' || c == '/')
		return 2;
	if (c == '+' || c == '-')
		return 1;
	return -1;
}
ll evalOp(ll a, ll b, char c){
	switch(c){
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
}
void solve(string str){
	stack<ll> values;
	stack<char> ops;
	for (int i = 0; i < str.length(); i++){
		if (str[i] == ' ')
			continue;
		else if (str[i] == '(')
			ops.push(str[i]);
		else if (isdigit(str[i])){
			ll val = 0;
			while (i < str.length() && isdigit(str[i])){
				val = (val * 10) + (str[i] - '0');
				if (i < str.length() - 1 && isdigit(str[i+1])) i++;
				else break; 
			}
			values.push(val);
		}
		else if (str[i] == ')'){
			while (!ops.empty() && ops.top() != '('){
				ll x1 = values.top(); values.pop();
				ll x2 = values.top(); values.pop();
				char op = ops.top(); ops.pop();
				values.push(evalOp(x2, x1, op));
			}
			if (!ops.empty())
				ops.pop();
		}
		else{
			while (!ops.empty() && prec(str[i]) <= prec(ops.top())){
				ll x1 = values.top(); values.pop();
				ll x2 = values.top(); values.pop();
				char op = ops.top(); ops.pop();
				values.push(evalOp(x2, x1, op));
			}
			ops.push(str[i]);
		}
	}
	while (!ops.empty()){
		ll x1 = values.top(); values.pop();
		ll x2 = values.top(); values.pop();
		char op = ops.top(); ops.pop();
		values.push(evalOp(x2, x1, op));
	}
	cout << values.top() << endl;
}
int main(){ 
    int t; cin >> t;
    cin.ignore();
    while (t--){
    	string s; getline(cin,s);
    	solve(s);
	}
} 
