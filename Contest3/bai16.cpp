#include<bits/stdc++.h>
using namespace std;
void smallestNum(int s, int d){
	if (s > d * 9){
		cout << "-1" << endl;
		return;
	}
	int result[d];
	s -= 1;
	for (int i = d - 1; i > 0; i--){
		if (s > 9){
			result[i] = 9;
			s -= 9;
		}
		else{
			result[i] = s;
			s = 0;
		}
	}
	result[0] = s + 1;
	for (int i = 0; i < d; i++)
		cout << result[i];
	cout << endl;
}
int main(){
	int s, d, T; cin >> T;
	while (T--){
		cin >> s >> d;
		smallestNum(s, d);
	}
}
