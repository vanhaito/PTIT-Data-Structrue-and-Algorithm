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
Node *ConstructTree(int inorder[], int levelorder[], int start, int end, int n){
	if (n <= 0)
		return NULL;
	Node *root = CreateNode(levelorder[0]);
	int index = -1;
	for (int i=start; i<=end; i++){
		if (levelorder[0] == inorder[i]){
			index = i;
			break;
		}
	}
	unordered_set<int> s;
	for (int i=start; i<index; i++) //insert left nodes
		s.insert(inorder[i]);
	int ls[s.size()];	//left
	int rs[end-start-s.size()];	//right
	int li = 0, ri = 0;
	for (int i=1; i<n; i++){
		if (s.find(levelorder[i]) != s.end())	// not exist
			ls[li++] = levelorder[i];
		else
			rs[ri++] = levelorder[i];
	}
	root->left = ConstructTree(inorder, ls, start, index-1, index-start);
	root->right = ConstructTree(inorder, rs, index+1, end, end-index);
	return root;
}
void printPostorder(Node *root){
	if(root){
		printPostorder(root->left);
		printPostorder(root->right);
		cout << root->data << " ";
	}
}
int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int *inorder = new int[n+1];
		int *levelorder = new int[n+1];
		for (int i=0; i<n; i++) cin >> inorder[i];
		for (int i=0; i<n; i++) cin >> levelorder[i];
		Node *root = ConstructTree(inorder, levelorder, 0, n-1, n);
		printPostorder(root);
		cout << endl;
	}
}
