#include<bits/stdc++.h>
using namespace std;
void solve(string str){
	stack<char> s;
	for (int i=0; i<str.length(); i++){
		if (str[i]==')' && !s.empty()){
			if (s.top() == '(')
				s.pop();
			else
				s.push(str[i]);
		}
		else
			s.push(str[i]);
	}
	int m = s.size();
	int n = 0;
	while (!s.empty() && s.top() == '('){
		s.pop();
		n++;
	}
	int res = m/2+n%2;
	cout << res << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		string str; cin >> str;
		solve(str);
	}
}
