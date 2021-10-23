#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<string> preProcess(ll n){
	vector<string> vtCubes;
	for (int i = 1; i * i * i <= n; i++){
		ll cube = i * i * i;
		stringstream ss; ss << cube;
		string cubeString; ss >> cubeString;
		vtCubes.push_back(cubeString);
	}
	return vtCubes;
}
string largestCube(string num, vector<string>vtCubes){
	reverse(vtCubes.begin(), vtCubes.end());
	int total = vtCubes.size();
	for (int i = 0; i < total; i++){
		string currCube = vtCubes[i];
		int index = 0;
		int digitsCube = currCube.length();
		int digitsNum = num.length();
		for (int j = 0; j < digitsNum; j++){
			if (num[j] == currCube[index])
				index++;
			if (digitsCube == index)
				return currCube;
		}
	}
	return "-1";
}
void solve(ll n){
	vector<string> vtCubes = preProcess(n);
	stringstream ss; ss << n;
	string num; ss >> num;
	cout << largestCube(num, vtCubes) << endl;
}
int main(){
	ll n; int T; cin >> T;
	while (T--){
		cin >> n;
		solve(n);
	}
}

