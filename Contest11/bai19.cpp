#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
};
typedef Node *Tree;
Node *CreateNode(int x){
	Node *p = new Node();
	if (!p) exit(1);
	p->data = x;
	p->right = p->left = NULL;
	return p;
}
void InsertNode(Tree &root, int x){
	if (root){
		if (root->data == x) return;
		else{
			if (x < root->data) InsertNode(root->left, x);
			else InsertNode(root->right, x);
		}
	}
	else{
		Node *p = CreateNode(x);
		root = p;
	}
}
void CreateTree(Tree &root){
	int n; cin >> n;
	int x;
	while (n--){
		cin >> x;
		InsertNode(root, x);
	}
}
void solve(Tree root){
	if(root){
		solve(root->left);
		solve(root->right);
		cout<< root->data << " ";
	}
}
int main(){
	int t; cin >> t;
	while (t--){
		Tree root;
		root = NULL;
		CreateTree(root);
		solve(root);
		cout << endl;
	}
}
