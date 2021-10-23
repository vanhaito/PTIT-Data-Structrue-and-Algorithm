#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	deque<int> q;
	while (n--){
		string str; cin >> str;
		if (str == "PUSHFRONT"){
			int x; cin >> x;
			q.push_front(x);
		}
		if (str == "POPFRONT"){
			if (!q.empty())
				q.pop_front();
		}
		if (str == "PRINTFRONT")
			if (!q.empty())
				cout << q.front() << endl;
			else cout << "NONE" << endl;
		if (str == "PUSHBACK"){
			int x; cin >> x;
			q.push_back(x);
		}
		if (str == "PRINTBACK"){
			if (!q.empty())
				cout << q.back() << endl;
			else cout << "NONE" << endl;
		}
		if (str == "POPBACK"){
			if (!q.empty())
				q.pop_back();
		}
	}
}
