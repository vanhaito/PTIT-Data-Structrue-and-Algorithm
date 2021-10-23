#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
};
Node *CreateNode(int x){
	Node *p = new Node();
	if (!p) exit(1);
	p->data = x;
	p->right = p->left = NULL;
	return p;
}
Node *binarySearch(int arr[], int s, int e){
	if (s > e)
		return NULL;
	int mid = (s+e)/2;
	Node *root = CreateNode(arr[mid]);
	root->left = binarySearch(arr, s, mid-1);
	root->right = binarySearch(arr, mid+1, e);
	return root;
}
void preOrder(Node *root){
	if (root){
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
int main(){
	int t; cin >> t;
	while (t--){
		int n, *arr; cin >> n;
		arr = new int[n+1];
		for (int i=0; i<n; i++) cin >> arr[i];
		sort(arr, arr+n);
		Node *root = binarySearch(arr, 0, n-1);
		preOrder(root);
		cout << endl;
	}
}
