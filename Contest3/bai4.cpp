#include <bits/stdc++.h>
using namespace std;
long long t, n, a[30];
void minSum(){
	sort(a, a+n);
	long long n1=0, n2=0;
	for(int i=0; i<n; i= i+2) {
		if(a[i] != 0){
			n1= n1*10 + a[i];
			a[i]=0;
		}
	}
	for(int i=0; i<n; i++) {
		if(a[i] != 0) n2= n2*10 + a[i];
	}
	cout << n1 + n2 << endl;
}

main(){
	cin>>t;
	while(t--){
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		minSum();
	}
}
