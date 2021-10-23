#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1005];
bool isEulerCycle(){
	vector<int> start(1005, 0), end(1005, 0);
	for (int i=1; i<=n; i++){
		int sum = 0;
		for (int j=0; j<adj[i].size(); j++){
			start[adj[i][j]]++;
			sum++;
		}
		end[i] = sum;
	}
	if (start == end)
		return true;
	return false;
}
int main(){
	int T; cin >> T;
	while (T--){
		cin >> n >> m;
		for (int i=0; i<1005; i++)
			adj[i].clear();
		for (int i=1; i<=m; i++){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
		}
		if (isEulerCycle()) cout << 1;
		else cout << 0;
		cout << endl;
	}
}
