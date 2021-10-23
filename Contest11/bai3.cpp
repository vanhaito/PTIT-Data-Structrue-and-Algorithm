#include<bits/stdc++.h>
using namespace std;
int search(int arr[], int x, int n){
	for (int i=0; i<n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}
void PrintPostOrder(int inOrder[], int preOrder[], int n){
	int root = search(inOrder, preOrder[0], n);
	if (root != 0)
		PrintPostOrder(inOrder, preOrder+1, root);
	if (root != n-1)
		PrintPostOrder(inOrder+root+1, preOrder+root+1, n-root-1);
	cout << preOrder[0] << " ";
}
int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int *inOrder = new int[n+1];
		int *preOrder = new int[n+1];
		for (int i=0; i<n; i++) cin >> inOrder[i];
		for (int i=0; i<n; i++) cin >> preOrder[i];
		PrintPostOrder(inOrder, preOrder, n);
		cout << endl;
	}
}
