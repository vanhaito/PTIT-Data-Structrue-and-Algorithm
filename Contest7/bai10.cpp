#include<bits/stdc++.h>
using namespace std;
bool check(string str, int i){
	if (i == 0)
		return true;
	if (str[i-1] == '-')
		return false;
	return true;
}
void evaluation(string str, vector<int>& v, bool add){
	stack<bool> s;
	s.push(true);
	int i = 0;
	while (str[i] != '\0'){
		if (str[i] == '+' || str[i] == '-'){
			i++;
			continue;
		}
		if (str[i] == '('){
			if (check(str, i))
				s.push(s.top());
			else
				s.push(!s.top());
		}
		else if (str[i] == ')')
			s.pop();
		else{
			if (s.top())                  
                v[str[i] - 'a'] += (check(str, i) ? add ? 1 : -1 :  
                                                  add ? -1 : 1); 
            else                 
                v[str[i] - 'a'] += (check(str, i) ? add ? -1 : 1 :  
                                                  add ? 1 : -1); 
		}
		i++;
	}
}
void solve(string str1, string str2){
	vector<int> v(26, 0);
	evaluation(str1, v, true);
	evaluation(str2, v, false);
	for (int i=0; i<26; i++){
		if (v[i] != 0){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}
int main(){
	int T; cin >> T;
	while (T--){
		string str1, str2;
		cin >> str1 >> str2;
		solve(str1, str2);
	}
}
