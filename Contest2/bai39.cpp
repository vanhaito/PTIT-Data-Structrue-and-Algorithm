#include<bits/stdc++.h>
using namespace std;
int main(){
	string s; long long n;
	cin >> s >> n;
	long long tmp = s.size();
	while (tmp < n){
		tmp *= 2;
	}
	int length = s.size();
	while (n > length){
		if (n > tmp/2){
			n -= tmp/2;
			n --;
			if (n == 0) n = tmp/2;
		}
		tmp /= 2;
	}
	cout << s[n-1];
}
