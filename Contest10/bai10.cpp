#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, m;
struct edge{
	int u;
	int v;
	int w;
};
edge edges[10005];
int parent[10005];
int rankz[10005];
bool compare(edge x, edge y){
	if(x.w < y.w) return true;
	return false;
}
int find(int u){
	if (parent[u] == u) return parent[u];
	return find(parent[u]);
}
bool merge(int u, int v){
	u = find(u); v = find(v);
	if (u == v) return false;
	if (rankz[u] == rankz[v]){
		rankz[u]++;
	}
	if (rankz[u] < rankz[v])
		parent[u] = v;
	else parent[v] = u;
	return true;
}
void solve(){
	long long res = 0;
	sort(edges, edges+m, compare);
	for (int i=0; i<m; i++){
		if (merge(edges[i].u, edges[i].v))
			res += edges[i].w;
	}
	cout << res << endl;
}
int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i=0; i<m; i++)
			cin >> edges[i].u >> edges[i].v >> edges[i].w;
		for (int i=1; i<=n; i++){
			parent[i] = i;
			rankz[i] = 0;
		}
		solve();
	}
}


