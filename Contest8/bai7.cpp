#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
void solve(long long n){
	queue<long long> q;
	q.push(1);
	long long res = 0;
	while (!q.empty()){
		long long x = q.front();
		q.pop();
		if (x <= n){
			res++;
			q.push(x*10);
			q.push(x*10+1);
		}
	}
	cout << res << endl;
}
int main(){
	int t; cin >> t;
	while (t--){
		long long n; cin >> n;
		solve(n);
	}
}
