#include<bits/stdc++.h>
using namespace std;
struct node{
	int val;
	int level;
};
int solve(int x, int y){
	queue<node> q;
	node n = {x, 0};
	q.push(n);
	set<int> visited;
	visited.insert(x);
	while (!q.empty()){
		node t = q.front();
		q.pop();
		if (t.val == y)
			return t.level;
		if (t.val*2==y || t.val-1==y)
			return t.level+1;
		if (visited.find(t.val*2)==visited.end() && t.val<y){
			n.val = t.val*2;
			n.level = t.level+1;
			q.push(n);
			visited.insert(t.val*2);
		}
		if (visited.find(t.val-1)==visited.end() && (t.val-1)>0){
			n.val = t.val-1;
			n.level = t.level+1;
			q.push(n);
			visited.insert(t.val-1);
		}
	}
}
int main(){
	int t; cin >> t;
	while (t--){
		int x, y; cin >> x >> y;
		cout << solve(x, y) <<endl;
	}
}
