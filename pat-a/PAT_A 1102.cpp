//PAT_A 1102
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 110;
struct node {
	int lchild, rchild;
}Node[maxn];
bool notRoot[maxn] = { false };//记录是不是根节点
int n, num = 0;
void print(int id) {
	printf("%d", id);
	num++;
	if (num < n)printf(" ");
	else printf("\n");
}
void inOrder(int root) {
	if (root == -1)return;
	inOrder(Node[root].lchild);
	print(root);
	inOrder(Node[root].rchild);
}
void bfs(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		print(now);
		if (Node[now].lchild != -1)q.push(Node[now].lchild);
		if (Node[now].rchild != -1)q.push(Node[now].rchild);
	}
}
void postOrder(int root) {//在后序遍历的时候交换左右子树
	if (root == -1)return;
	postOrder(Node[root].lchild);
	postOrder(Node[root].rchild);
	swap(Node[root].lchild, Node[root].rchild);
}
int strToNum(char c) {//这里传进来的全是孩子节点，不可能时根节点
	if (c == '-')return -1;
	else {
		notRoot[c - '0'] = true;//节点c不是根节点
		return c - '0';
	}
}
int findRoot() {
	for (int i = 0; i < n; i++) {
		if (notRoot[i] == false)return i;
	}
}
int main() {
	char lchild, rchild;
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		(void)getchar();
		(void)scanf("%c %c", &lchild, &rchild);
		Node[i].lchild = strToNum(lchild);
		Node[i].rchild = strToNum(rchild);
	}
	int root = findRoot();
	postOrder(root);
	bfs(root);
	num = 0;
	inOrder(root);
	return 0;
}
