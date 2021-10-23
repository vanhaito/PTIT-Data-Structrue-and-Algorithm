#include<bits/stdc++.h>
using namespace std;
int n, m;
int f[1005];
vector<pair<int, int> > edge;
int find(int i){
	if (f[i] == 0)
		return i;
	return find(f[i]);
}
void Union(int x, int y){
	int xset = find(x);
	int yset = find(y);
	if (xset != yset)
		f[xset] = yset;
}	
bool isCycle(){
	for (int i=0; i<m; i++){
		int x = find(edge[i].first);
		int y = find(edge[i].second);
		if (x == y)
			return true;
		Union(x, y);
	}
	return false;
}
int main(){
	int T; cin >> T;
	while (T--){
		cin >> n >> m;
		edge.clear();
		for (int i=1; i<=m; i++){
			int x, y; cin >> x >> y;
			edge.push_back({x, y});
		}
		memset(f, 0, sizeof(f));
		if (isCycle()) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
