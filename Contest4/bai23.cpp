#include <bits/stdc++.h>

using namespace std;
long long t, K;
int n;

long long Mul(int n){
	if(n==0) return 1;
	if(n==1) return 2;
	long long p= Mul(n/2);
	if(n%2) return 2 *p *p;
	return p* p;
}

main(){
	cin>>t;
	while(t--){
		cin>>n>>K;
		long long len= Mul(n)/2;
		while(1){
			if(n==1){
				cout<<1;
				break;
			}
			if(len == K){
				cout<<n;
				break;
			}
			if(K> len){
				K= len - (K - len);
			}
			n--;
			len= len/2;
		}
		cout<<endl;
	}
}
