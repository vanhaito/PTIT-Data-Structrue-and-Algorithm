#include<iostream>
#include<vector>
#include<cmath>
 
using namespace std;
int n, k, S, Sum, dem;
vector<int> A;
 
 
bool CheckSumArr() {
	int sum = 0;
	for (size_t i = 1; i <= k; i++)
	{
		sum += A[i];
	}
	if (sum == S)
		return true;
	return false;
}
 
void dequy(int i) {
	for (int j = A[i - 1] + 1; j < A.size() - k + i; j++) {
		A[i] = j;
		Sum += A[i];
		if (i == k) {
			if (CheckSumArr()) {
				dem++;
			}
			if (Sum > S) {
				Sum -= A[i];
				return;
			}
		}
		else {
			if (Sum < S)
				dequy(i + 1);
			else {
				Sum -= A[i];
				return;
			}
		}
		Sum -= A[i];
	}
}
 
int main() {
	while(true) {
		cin >> n >> k >> S;
		if (n == 0 && k == 0 && S == 0) {
			break;
		}
		dem = 0, Sum = 0;
		A.push_back(0);
		for (int i = 1; i <= n; i++) {
			A.push_back(i);
		}
		dequy(1);
		cout << dem << endl;
		A.clear();
	}
	return 0;
}
