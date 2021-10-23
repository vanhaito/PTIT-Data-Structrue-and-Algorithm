#include<bits/stdc++.h>
using namespace std;
int makeEqualLength(string &s1, string &s2){
	int len1 = s1.size();
	int len2 = s2.size();
	if (len1 < len2){
		for (int i = 0; i < len2 - len1; i++)
			s1 = '0' + s1;
		return len2;
	}
	else if (len1 > len2){
		for (int i = 0; i < len1 - len2; i++)
			s2 = '0' + s2;
	}
	return len1;
}
string addBitStrings(string first, string second){
	string res;
	int length = makeEqualLength(first, second);
	int carry = 0;
	for (int i = length - 1; i >= 0; i--){
		int firstbit = first.at(i) - '0';
		int secondbit = second.at(i) - '0';
		int sum = (firstbit + secondbit + carry) % 2 + '0';
		carry = (firstbit + secondbit + carry) / 2;
		res = char(sum) + res;
	}
	if (carry)
		res = '1' + res;
	return res;
}
int multiplySingleBit(string a, string b){
	return (a[0] - '0') * (b[0] - '0');
}
long long multiply(string x, string y){
	int n = makeEqualLength(x, y);
	if (n == 0)
		return 0;
	if (n == 1)
		return multiplySingleBit(x, y);
	int first = n / 2;
	int second = n - first;
	string xl = x.substr(0, first);
	string xr = x.substr(first, second);
	string yl = y.substr(0, first);
	string yr = y.substr(first, second);
	long long p1 = multiply(xl, yl);
	long long p2 = multiply(xr, yr);
	long long p3 = multiply(addBitStrings(xl, xr), addBitStrings(yl, yr));
	return p1 * (1<<(2 * second)) + (1 << second) * (p3 - p1 - p2) + p2; 
}
int main(){
	int T; cin >> T;
	while (T--){
		string x, y; cin >> x >> y;
		cout << multiply(x, y) << endl;
	}
}
