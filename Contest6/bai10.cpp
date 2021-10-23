#include<bits/stdc++.h>
using namespace std;
int main(){
	int T; cin >> T;
	while (T--){
		int n, tmp; cin >> n;
		bool used[10];
		memset(used, false, sizeof(used));
		for (int i=0; i<n; i++){
			cin >> tmp;
			while (tmp){
				used[tmp%10] = true;
				tmp /= 10;
			}
		}
		for (int i=0; i<10; i++)
			if(used[i]) cout << i << " ";
		cout << endl;
	}
}
