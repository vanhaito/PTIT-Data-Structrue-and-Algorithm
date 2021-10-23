#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;
int minStringValue(string s, int k){
	int n = s.length();
	if (k > n)
		return 0;
	int count[MAX_CHAR] = {0};
	for (int i = 0; i < n; i++)
		count[s[i] - 'A']++;
	priority_queue<int> pq;
	for (int i = 0; i < MAX_CHAR; i++)
		pq.push(count[i]);
	while (k--){
		int tmp = pq.top();
		pq.pop();
		tmp -= 1;
		pq.push(tmp);
	}
	long long result = 0;
	while (!pq.empty()){
		int tmp = pq.top();
		result += tmp*tmp;
		pq.pop();
	}
	return result;
}
int main(){
	string s; int k, T; cin >> T;
	while (T--){
		cin >> k >> s;
		cout << minStringValue(s, k) << endl;
	}
	return 0;
}
