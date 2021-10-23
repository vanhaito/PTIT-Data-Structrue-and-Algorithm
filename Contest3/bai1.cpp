#include<bits/stdc++.h>
using namespace std;
int money[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int n, k;
void solution(){
	k = 0;
	sort(money, money+10, greater<int>());
	for (int i = 0; i < 10; i++){
		if (n >= money[i]){
			k += n / money[i];
			n %= money[i];
		}
	}
	cout << k << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		solution();
	}
}
