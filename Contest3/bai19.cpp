#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void Solution(ll nr, ll dr){
	if (nr == 0 || dr == 0)
		return;
	if (dr % nr == 0){
		cout << "1/" << dr/nr;
		return;
	}
	if (nr % dr == 0){
		cout << nr/dr;
		return ;
	}
	if (nr > dr){
		cout << nr/dr << " + ";
		Solution(nr%dr, dr);
		return;
	}
	ll n = dr/nr + 1;
	cout << "1/" << n << " + ";
	ll new_nr = nr * n - dr;
	ll new_dr = dr * n;
	Solution(new_nr, new_dr);
}
int main(){
	ll nr, dr, t; cin >> t;
	while(t--){
		cin >> nr >> dr;
		Solution(nr, dr);
		cout << endl;
	}
}
