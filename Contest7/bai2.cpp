#include<bits/stdc++.h>
using namespace std;
int main(){
	int T; cin >> T;
	stack<int> S;
	string str; int n;
	while (T--){
		cin >> str;
		if (str == "PUSH"){
			cin >> n;
			S.push(n);
		}
		else if (str == "PRINT"){
			if (S.empty()) cout << "NONE" << endl;
			else cout << S.top() << endl;
		}
		else if (str == "POP"){
			if (!S.empty()) S.pop();
		}
	}
}
