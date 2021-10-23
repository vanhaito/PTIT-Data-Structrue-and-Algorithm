#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	queue<int> q;
	while (n--){
		string str; cin >> str;
		if (str == "PUSH"){
			int x; cin >> x;
			q.push(x);
		}
		if (str == "POP"){
			if (!q.empty())
				q.pop();
		}
		if (str == "PRINTFRONT")
			if (!q.empty())
				cout << q.front() << endl;
			else cout << "NONE" << endl;
	}
}
