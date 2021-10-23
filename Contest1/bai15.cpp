#include <bits/stdc++.h>
using namespace std;
int n, t, a[100];
string s;
void start(){
	cin>>n;
	cin>>s;
}
void string_to_arr(){
	for(int i=0; i<s.size(); i++) a[i+1]= s[i] - '0';
}
void in(){
	for(int i=0; i<s.size(); i++) cout<<a[i+1];
	cout<<endl;
}
void tohop(){
	int n=s.size();
	int i=n-1;
	while(i>0 && a[i]>= a[i+1]) i--;
	if(i>0){
		for(int j=i+1; j<n; j++){
			for(int h=j+1; h<=n; h++){
				if(a[j]> a[h]) {
					int swap=a[j]; 
					a[j]= a[h];
					a[h]= swap;
				}
			}
		}
		for(int j=i+1; j<=n; j++){
			if(a[i]< a[j]) {
				int swap=a[i]; 
				a[i]= a[j];
				a[j]= swap;
				break;
			}
		}
		in();
	}
	else cout<<"BIGGEST"<<endl;
}
main(){
	cin>>t;
	while(t--){
		start();
		string_to_arr();
		cout<<n<<" ";
		tohop();
	}
}

