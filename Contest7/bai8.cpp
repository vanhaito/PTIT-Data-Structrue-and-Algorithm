#include<bits/stdc++.h>
using namespace std;
void solve(string str){
	stack<int> s;
	for (int i = 0; i < str.size(); i++){
		if (str[i] == '(')
			s.push(i);
		else if (!s.empty() && str[i] == ')'){
			int k = s.top(); s.pop();
			if (str[k-1] == '-'){
				for (int j = k; j <= i; j++){
					if (str[j] == '+') str[j] = '-';
					else if(str[j] == '-') str[j] = '+';
				}
			}
		}
	}
	for (int i = 0; i < str.size(); i++)
		if (str[i] != '(' && str[i] != ')')
			cout << str[i];
	cout << endl;
}
int main(){
	int t; cin >> t;
	while (t--){
		string str; cin >> str;
		solve(str);
	}
}
