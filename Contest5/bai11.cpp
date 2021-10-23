//han che n<30
// n>30 phai lam voi so lon
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string add(string a, string b){
	while (a.size() < b.size()) a = "0" + a;
	while (a.size() > b.size()) b = "0" + b;
	string res = "";
	int n = a.size() - 1;
	int carry = 0;
	for (int i = n; i >= 0; i--){
		int k = int(a[i] - '0') + int(b[i] - '0') + carry;
		res = char(k%10 + '0') + res;
		carry = k / 10;
	}
	if (carry > 0) res = char(carry + '0') + res;
	return res;
}
string multiply(string s1, string s2){
	int n1 = s1.size();
	int n2 = s2.size();
	int n = n1+n2;
	vector<int> a,b;
	for (int i = 0; i < n1; i++)
		a.push_back(int(s1[i] - '0'));
	for (int i = 0; i < n2; i++)
		b.push_back(int(s2[i] - '0'));
	vector<vector<int> > res(n2);
	int index = 0;
	for (int i = n2-1; i >= 0; i-- ){
		int t = 0;
		while (t < index){
			res[index].push_back(0);
			t++;
		}
		int carry = 0; int k = 0;
		for (int j = n1-1; j >= 0; j--){
			k = a[j]*b[i] + carry;
			res[index].push_back(k%10);
			carry = k/10;
		}
		if (carry > 0) res[index].push_back(carry);
		while(res[index].size() < n)
			res[index].push_back(0);
		reverse(res[index].begin(), res[index].end());
		index++;
	}
	int carry = 0;
	string ans = "";
	for (int j = res[0].size()-1; j >= 0; j--){
		int k = carry;
		for (int i = 0; i < res.size(); i++)
			k += res[i][j];
		ans = char(k%10 + '0') + ans;
		carry = k/10;
	}	
	if (carry > 0) ans = char(carry+'0') + ans;
	while (ans[0] == '0') ans.erase(ans.begin());
	return ans;
}
void solve(int n) { 
    vector<string> catalan(n+1);   
    catalan[0] = catalan[1] = "1"; 	
    for (int i = 2; i <= n; i++) 
    { 
        catalan[i] = "0"; 
        for (int j = 0; j < i; j++) {
        	catalan[i] = add(catalan[i], multiply(catalan[j], catalan[i-j-1]));        	
		}              
    } 
    cout << catalan[n] << endl; 
} 
int main() { 
	int T, n;cin>>T;
	while(T--){
		cin>>n; 
		solve(n);
	}	
} 
