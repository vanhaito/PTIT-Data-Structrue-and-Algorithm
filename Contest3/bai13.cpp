#include<bits/stdc++.h>
using namespace std;
void rearrangeString(string s, int k){
	priority_queue<pair< int, char> >pq;
	map<char,int>m;
	int n= s.length();
	for(int i = 0; i < n; i++)
	m[s[i]]++;
	map<char, int>::iterator it;
	for(it = m.begin();it != m.end();it++){
		char c = it->first;
		int f = it->second;
		pq.push({f,c});
	}
	char result[n];
	memset(result, '#', sizeof(result));
	bool flag = true;
	while(!pq.empty()){
		pair <int, char> p; p = pq.top();
		pq.pop();
		char c = p.second;
		int f = p.first;
		int t = 0;
		while(result[t] != '#') 
		t++;
		if (t == n){
			flag = false;
			break;
		}
		while(f > 0 && t < n){
			result[t] = c;
			t += k;
			f--;
		}
		if (f){
			flag = false;
			break;
		}
	}
	if (flag) cout << 1 << endl;
	else cout << "-1" << endl;
}
int main(){
	int T; cin>>T;
    while(T--){
    	string s; int k;
    	cin >> k >> s;
    	rearrangeString(s, k);	
	}
}
