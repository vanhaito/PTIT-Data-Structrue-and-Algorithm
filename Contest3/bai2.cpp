#include<bits/stdc++.h>
using namespace std;
int toFive(string s){
	int n = 0, m;
	for (int i = 0; i < s.size(); i++){
		m = s[i] - '0';
		if (m == 6)
			n = n*10 + 5;
		else n = n*10 + m;
	}
	return n;
}
int toSix(string s){
	int n = 0, m;
	for (int i = 0; i < s.size(); i++){
		m = s[i] - '0';
		if (m == 5)
			n = n*10 + 6;
		else n = n*10 + m;
	}
	return n;
}
int main(){
	string s1, s2;
	cin >> s1 >> s2;
	cout << toFive(s1) + toFive(s2) << " " << toSix(s1) + toSix(s2);
}

