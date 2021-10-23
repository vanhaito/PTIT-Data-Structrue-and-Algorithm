#include<bits/stdc++.h>
using namespace std;
int n, m;
bool used[1005];
vector<int> vt[1005];
vector<pair<int,int> > ans;
void Reinit(){
	for (int i=0; i<1005; i++)
		vt[i].clear();
	memset(used, false, sizeof(used));
}
void BFS(int u){
	queue<int> Q;
	Q.push(u);
	used[u] = true;
	while(!Q.empty()){
		int s = Q.front();
		Q.pop();
		for (int t=0; t<vt[s].size(); t++){
			if (!used[vt[s][t]]){
				Q.push(vt[s][t]);
				used[vt[s][t]] = true;	
			}
		}
	}
}
int TPLT(){
	int res = 0;
	for (int  i=1; i<=n; i++){
		if (!used[i]){
			res++;
			BFS(i);
		}
	}
	return res;
}
void Canhcau(int c, int res, vector<pair<int,int> > tmp){
	for (int i=0; i<m; i++){
		if (i != c){
			vt[tmp[i].first].push_back(tmp[i].second);
			vt[tmp[i].second].push_back(tmp[i].first);
		}
	}
	int d = TPLT();
	if (d > res){
		if(tmp[c].first < tmp[c].second)
			ans.push_back({tmp[c].first, tmp[c].second});
		else
			ans.push_back({tmp[c].second, tmp[c].first});
	}
}
int main(){
	int T; cin >> T;
	while (T--){
		Reinit();
		ans.clear();
		cin >> n >> m;
		vector<pair<int,int> > tmp;
		for (int i=0; i<m; i++){
			int x, y; cin >> x >> y;
			tmp.push_back({x, y});
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		int res = TPLT();
		for (int i=0; i<m; i++){
			Reinit();
			Canhcau(i, res, tmp);
		}
		sort(ans.begin(), ans.end());
		for (int i=0; i<ans.size(); i++)
			cout << ans[i].first << " " << ans[i].second << " ";
		cout << endl;
	}
}

