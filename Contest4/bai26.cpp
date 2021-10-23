#include<bits/stdc++.h>
using namespace std;
int equal(string &s1, string &s2){
	int len1 = s1.size();
	int len2 = s2.size();
	if (len1 < len2){
		for (int i = 0; i < len2 - len1; i++)
			s1 = '0' + s1;
		return len2;
	}
	else if(len1 > len2){
		for (int i = 0; i < len1 - len2; i++)
			s2 = '0' + s2;
	}
	return len1;
}
string addBasedK(string s1, string s2, int k){
	string res;
	int length = equal(s1, s2);
	int mod = 0;
	for (int i = length - 1; i >= 0; i--){
		int a = s1.at(i) - '0';
		int b = s2.at(i) - '0';
		int sum = (a + b + mod) % k + '0';
		mod = (a + b + mod) / k;
		res  = char(sum) + res;
	}
	if (mod){
		char x = '0' + mod;
		res = x + res;
	}
	return res;
}
int main(){
	string a, b; int k;
	cin >> k >> a >> b;
	cout << addBasedK(a, b, k);
}
