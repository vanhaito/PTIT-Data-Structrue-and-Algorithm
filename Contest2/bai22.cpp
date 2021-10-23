#include<bits/stdc++.h>
using namespace std;

int a[11][11];
int n;
char x[100];
bool check;

void nhap(){
	for(int i=0; i < n; i++)
		for(int j=0 ;j < n; j++)
			cin >> a[i][j];
}

void in(int k){
	for(int i = 0; i < k; i++)
		cout << x[i];
	cout << " ";
	check = true;
}

void Try(int i, int j, int k){
	if (i == n-1 && j == n-1){
		in(k);
		return;
	}
	if (i < n-1 && a[i+1][j] == 1){
		x[k] = 'D';
		Try(i+1, j, k+1);
	}
	if (j < n-1 && a[i][j+1] == 1){
		x[k] = 'R';
		Try(i, j+1, k+1);
	}
}

int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		nhap();
		check = false;
		if (a[0][0] != 1)	cout << "-1";
		else{
			Try(0, 0, 0);
			if(!check)	cout << "-1"; 
		}
		cout << endl;
	}
}
