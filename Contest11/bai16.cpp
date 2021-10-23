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
void Insert(Node *root, int a, int b, char c){
    if(a == root->data){
        if(c == 'L'){
            root->left = CreateNode(b);
            return;
        }
        if(c=='R'){
            root->right= CreateNode(b);
            return;
        }
    }
    else if(root->left==NULL && root->right==NULL)
        return;
    else{
        if(root->left)
            Insert(root->left, a, b, c);
        if(root->right)
            Insert(root->right, a, b, c);
    }
}
int maxSum(Node *root, int &res){
	if (!root) return 0;
	if (!root->left && !root->right) return root->data;
	int ls = maxSum(root->left, res);
	int rs = maxSum(root->right, res);
	if (root->left && root->right){
		res = max(res, ls+rs+root->data);
		return max(ls, rs) + root->data;
	}
	if (!root->left)
		return rs + root->data;
	else
		return ls + root->data;
}
int Result(Node *root){
	int res = INT_MIN;
	maxSum(root, res);
	return res;
}
int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		Node *root = NULL;
		while (n--){
			int a, b; char c;
			cin >> a >> b >> c;
			if (root == NULL)
				root = CreateNode(a);
			Insert(root, a, b, c);
		}
		cout << Result(root) << endl;
	}
}
