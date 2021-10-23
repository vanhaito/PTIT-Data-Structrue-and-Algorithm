#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1005];
int isEulerian(){
	int odd = 0;
	for (int i=1; i<=n; i++){
		if (adj[i].size()%2 != 0)
			odd++;
	}
	if (odd > 2)
		return 0;
	return (odd == 2)? 1 : 2;
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
			adj[y].push_back(x);
		}
		cout << isEulerian() << endl;
	}
}
