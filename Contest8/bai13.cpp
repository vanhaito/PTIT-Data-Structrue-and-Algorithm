#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
bool isValid(string str){
	map<int, int> m;
	for (int i = 0; i < str.length(); i++){
		if (m.find(str[i]-'0') != m.end())
			return false;
		else if (str[i]-'0' > 5)
			return false;
		else
			m[str[i]-'0'] = 1;
	}
	return true;
}
void generate(){
	queue<string> q;
	q.push("1"); q.push("2"); q.push("3"); q.push("4"); q.push("5");
	ans.push_back("0");
	while (!q.empty()){
		string x = q.front(); q.pop();
		if (x == "54321")
			break;
		if (isValid(x))
			ans.push_back(x);
		if (x.length() == 6)
			continue;
		for (int i = 0; i <= 5; i++){
			string z = to_string(i);
			string tmp = x + z;
			q.push(tmp);
		}
	}
}
bool cmp(string a, string b){
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}
int count(string l, string r){
	int  res = 0;
	for (int i = 0; i < ans.size(); i++){
		string a = ans[i];
		if (cmp(l, a) && cmp(a, r))
			res++;
		else if (a == l || a == r)
			res++;
	}
	return res;
}
int main(){
	int t; cin >> t;
	generate();
	while (t--){
		string l, r;
		cin >> l >> r;
		cout << count(l, r) << endl;
	}
}
