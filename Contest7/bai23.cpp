#include<bits/stdc++.h>
using namespace std;
void solve(string str){
	stack<int> ig;
	stack<char> sg;
	string tmp = "", res = "";
	for (int i = 0; i < str.length(); i++){
		int num  = 0;
		if (str[i] >= '0' && str[i] <= '9'){
			while (str[i] >= '0' && str[i] <= '9'){
				num  = num*10 + str[i] - '0';
				i++;
			}
			i--;
			ig.push(num);
		}
		else if (str[i] == ']'){
			tmp = "";
			num = 0;
			if (!ig.empty()){
				num = ig.top();
				ig.pop();
			}
			while (!sg.empty() && sg.top() != '['){
				tmp = sg.top() + tmp;
				sg.pop();
			}
			if (!sg.empty() && sg.top() == '[')
				sg.pop();
			for (int j = 0; j < num; j++)
				res = res + tmp;
			for (int j = 0; j < res.length(); j++)
				sg.push(res[j]);
			res = "";
		}
		else if (str[i] == '['){
			if (str[i-1] >= '0' && str[i-1] <= '9')
				sg.push(str[i]);
			else{
				sg.push(str[i]);
				ig.push(1);
			}
		}
		else
			sg.push(str[i]);
	}
	while (!sg.empty()){
		res = sg.top() + res;
		sg.pop();
	}
	cout << res << endl;
}
int main(){
	int t; cin >> t;
	while (t--){
		string str; cin >> str;
		solve(str);
	}
}
