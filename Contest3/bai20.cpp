#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll countSwap(string s){
	vector<int> pos;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '[')
			pos.push_back(i);
	int c = 0, p = 0;
	ll sum = 0;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '['){
			c++;
			p++;
		}
		else if (s[i] == ']')
			c--;
		if (c < 0){
			sum += pos[p] - i;
			swap(s[i], s[pos[p]]);
			p++;
			c = 1;
		}
	}
	return sum;
}
int main(){
	string s; int t; cin >> t;
	while(t--){
		cin >> s;
		cout << countSwap(s) << endl;
	}
}
