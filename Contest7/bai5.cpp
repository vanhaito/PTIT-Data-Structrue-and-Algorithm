#include<bits/stdc++.h>
using namespace std;
void solve(string str){
	stack<int> s;
	s.push(-1);
	int lmax=0;
	for (int i=0; i<str.length(); i++){
		if (str[i]=='(')
			s.push(i);
		else{
			s.pop();
			if (s.empty()){
				s.push(i);
				continue;
			}
			int curr_len = i-s.top();
			if (lmax < curr_len)
				lmax = curr_len;
		}
	}
	cout << lmax << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		string s; cin >> s;
		solve(s);
	}
}
