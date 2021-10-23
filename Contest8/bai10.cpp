#include<bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
int solve(int n){
	unordered_set<int> visit;
	visit.insert(n);
	queue<ii> q;
	q.push(ii(n,0));
 
	while(!q.empty()){
		ii t=q.front();
		q.pop();
		if(t.first==1) return t.second;
		if(t.first-1==1) return t.second+1;
 
		if(visit.find(t.first-1)==visit.end()&&t.first-1>0){
			q.push(ii(t.first-1,t.second+1));
			visit.insert(t.first-1);
		}
		for(int i=2;i*i<=t.first;i++){
			if(t.first%i==0){
				if(visit.find(t.first/i)==visit.end()){
					q.push(ii(t.first/i,t.second+1));
					visit.insert(t.first/i);
				}
			}
		}
	}
}
int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		cout << solve(n) << endl;
	}
}
