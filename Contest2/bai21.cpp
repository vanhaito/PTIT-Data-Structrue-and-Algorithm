#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int X[MAX], n;
string s;
bool chuaxet[MAX];

void init(){
	cin >> s;
	n = s.size();
	for(int i = 1; i <= n; i++)
		chuaxet[i] = true;
}

void result(){
	for(int i = 1; i <= n; i++){
		int j = X[i] - 1;
		cout << s[j];
	}
	cout << " ";
}

void Try(int i){
	for(int j = 1; j <= n; j++){
		if (chuaxet[j]){
			X[i] = j;
			chuaxet[j] = false;
			if (i == n) result();
			else Try(i+1);
			chuaxet[j] = true;
		}
	}	
}

int main(){
	int t; cin >> t;
	while(t--){
		init();
		Try(1);
		cout << endl;
	}
}
