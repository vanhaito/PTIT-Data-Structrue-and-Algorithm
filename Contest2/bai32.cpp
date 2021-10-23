#include<bits/stdc++.h>
using namespace std;
vector<string> result;
bool isBracket(char c){
	return ((c == '(') || ( c == ')'));
}
bool isString(string s){
	int c = 0;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '(')
			c++;
		else if (s[i] == ')')
			c--;
		if (c < 0)
			return false;
	}
	return (c == 0);
}
void removeBracket(string s){
	set<string> visit;
	queue<string> q;
	string tmp;
	bool level;
	q.push(s);
	while (!q.empty()){
		s = q.front();
		q.pop();
		if (isString(s)){
			result.push_back(s);
			level = true;
		}
		if (level)
			continue;
		for (int i = 0; i < s.length(); i++){
			if (!isBracket(s[i]))
				continue;
			tmp = s.substr(0, i) + s.substr(i+1);
			if (visit.find(tmp) == visit.end()){
				q.push(tmp);
				visit.insert(tmp);
			}
		}
	}
}
int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		removeBracket(s);
		if(result.size() == 1 && isString(result[0])) cout << -1 << endl;
		else{
			sort(result.begin(), result.end());
			for(int i = 0; i < result.size(); i++)
				cout << result[i] << " ";
			cout << endl;	
		}
		result.clear();
	}
}
