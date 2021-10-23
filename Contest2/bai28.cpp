#include<bits/stdc++.h>
using namespace std;
int n, c=0;
int a[100];

void result(int b[],int k){
    cout<<"[";
    int i;
    for(i = 0; i < k-1; i++)
    	cout << b[i] << " ";
    cout<<b[i]<<"] ";
    c++;
}

void Try(int b[], int x, int i, int k){
	for(int j = k; j >= 0; j--){
		if(a[j] <= x){
			b[i] = a[j];
			if(b[i] == x) result(b, i+1);
			else{
				int y = x - b[i];
				if(y >= a[j]) Try(b, y, i+1, j);
				else Try(b, y, i+1, j-1);
			}
		}
	}
}

int main(){
	int t; cin>>t;
	while(t--){
		int x;
		cin>>n>>x;
		for(int i = 0; i < n; i++)
			cin>>a[i];
		sort(a, a+n, greater<int >());
		int b[100] = {};
		Try(b, x, 0, n-1);
		if(c == 0) cout<<-1;
		cout<<endl;
	}
}
