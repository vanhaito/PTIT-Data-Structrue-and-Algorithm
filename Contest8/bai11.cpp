#include<bits/stdc++.h>
using namespace std;
const long limit = 2e5+5;
long long x, y, t;
int d[limit] = {0};
vector<long long> a;
bool ok[limit];
int dem[limit];
vector<long long> ke[limit];
queue<long long> q;
void sieve(){
	for (int i = 2; i <= 9999; i++){
		if (d[i] == 0){
			for (int j = i*i; j <= 9999; j += i)
				d[j] = 1;
		}
	}
	for (int i = 1000; i <= 9999; i++)
		if (d[i] == 0)
			a.push_back(i);
}
bool check(long long x, long long y){
	int d = 0;
	while (x && y){
		if (x%10 != y %10) d++;
		x /= 10; y /= 10;
	}
	return d == 1;
}
void init(){
	for (int i = 0; i < a.size()-1; i++){
		for (int j = i+1; j < a.size(); j++){
			if (check(a[i], a[j])){
				ke[a[i]].push_back(a[j]);
				ke[a[j]].push_back(a[i]);
			}
		}
	}
}
int BFS(long long u, long long d){
	q.push(u);
	dem[u] = 0;
	while (q.size() > 0){
		u = q.front();
		q.pop();
		ok[u] = true;
		if (u == d) return dem[d];
		for (int i = 0; i < ke[u].size(); i++){
			long long v = ke[u][i];
			if (ok[v]) continue;
			ok[v] = true;
			dem[v] = dem[u] + 1;
			q.push(v);
		}
	}
}
int main(){
	sieve();
	init();
	cin >> t;
	while (t--){
		for (int i = 0; i < limit; i++){
			ok[i] = false;
			dem[i] = 0;
		}
		while (q.size()) q.pop();
		cin >> x >> y;
		cout << BFS(x, y) << endl;
	}
	return 0;
}
