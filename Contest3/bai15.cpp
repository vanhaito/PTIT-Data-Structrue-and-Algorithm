#include<bits/stdc++.h>
using namespace std;
void Survival(int n, int s, int m){
	if ((n * 6) < (m * 7) && s > 6 || m > n)
		cout << "-1" << endl;
	else{
		int days = (m * s) / n;
		if ((m * s) % n != 0)
			days++;
		cout << days << endl;
	}
}
int main(){
	int n, s, m, T; cin >> T;
	while (T--){
		cin >> n >> s >> m;
		Survival(n, s, m);
	}
}
