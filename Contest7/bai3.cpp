#include<bits/stdc++.h>
using namespace std;
void solve(){
	stack<char> s;
	string str; getline(cin,str);;
	str = str + " ";
	for (int i=0; i<str.length(); i++){
		while (i<str.length() && str[i]!=' '){
			s.push(str[i]);
			i++;
		}
		while (!s.empty()){
			cout << s.top();
			s.pop();
		}
		cout << str[i];
	}
	cout << endl;
}
int main(){
	int T; cin >> T; cin.ignore();
	while (T--){
		solve();
	}
}
