//PAT_A 1020
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 50;
struct  node{
	int data;
	node* lchild;
	node* rchild;
};
int pre[maxn], in[maxn], post[maxn];//先序，中序，后序
int n;//节点个数
node* create(int postL, int postR, int inL, int inR) {//由后序序列和中序序列建立二叉树
	if (postL > postR)return NULL;
	node* root = new node;
	root->data = post[postR];//跟节点为后序遍历的最后一个
	int k = inL;
	for (k = inL; k <= inR; k++) {
		if (in[k] == root->data)break;//中序中找这个根节点元素，将根节点一分为2
	}
	int numLeft = k - inL;//左子树节点个数
	root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);//递归建立左右子树
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
	return root;
}
int num = 0;
void bfs(node* root) {//层序遍历二叉树
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node* now = q.front();
		q.pop();
		printf("%d", now->data);
		num++;
		if (num < n)printf(" ");
		if (now->lchild != NULL)q.push(now->lchild);
		if (now->rchild != NULL)q.push(now->rchild);
	}
}
int main() {
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &post[i]);
	}
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &in[i]);
	}
	node* root = create(0, n - 1, 0, n - 1);
	bfs(root);
	return 0;
}