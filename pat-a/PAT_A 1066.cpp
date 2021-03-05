//PAT_A 1066
#include<cstdio>
#include<algorithm>
using namespace std;
struct node {
	int v, height;
	node* lchild;
	node* rchild;
}*root;
node* newNode(int v) {
	node* Node = new node;
	Node->v = v;
	Node->lchild = Node->rchild = NULL;
	Node->height = 1;//节点初始高度为1
	return Node;
}
int getHeight(node* root) {
	if (root == NULL)return 0;
	return root->height;
}
void updateHeight(node* root) {
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
int getBalanceFactor(node* root) {
	return getHeight(root->lchild) - getHeight(root->rchild);
}
void L(node*& root) {//左旋
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void R(node*& root) {//右旋
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(node*& root, int v) {
	if (root == NULL) {
		root = newNode(v);
		return;
	}
	if (v < root->v) {
		insert(root->lchild, v);//像左子树插入
		updateHeight(root);
		if (getBalanceFactor(root) == 2) {
			if (getBalanceFactor(root->lchild) == 1) {//LL
				R(root);
			}
			else if (getBalanceFactor(root->lchild) == -1) {//LR
				L(root->lchild);
				R(root);
			}
		}
	}
	else {
		insert(root->rchild, v);
		updateHeight(root);
		if (getBalanceFactor(root) == -2) {
			if (getBalanceFactor(root->rchild) == -1) {//RR
				L(root);
			}
			else if (getBalanceFactor(root->rchild) == 1) {//RL
				R(root->rchild);
				L(root);
			}
		}
	}
}
node* create(int data[], int n) {
	node* root = NULL;
	for (int i = 0; i < n; i++) {
		insert(root, data[i]);
	}
	return root;
}
int main() {
	int n, v;
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &v);
		insert(root, v);
	}
	printf("%d\n", root->v);
	return 0;
}