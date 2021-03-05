//PAT_A 1099
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 110;
struct node {
	int data;
	int lchild;
	int rchild;
}Node[maxn];
int n, in[maxn], num = 0;
void inOrder(int root) {
	if (root == -1)return;
	inOrder(Node[root].lchild);
	Node[root].data = in[num++];
	inOrder(Node[root].rchild);
}
void bfs(int root) {
	queue<int> q;
	q.push(root);
	num = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d", Node[now].data);
		num++;
		if (num < n)printf(" ");
		if (Node[now].lchild != -1)q.push(Node[now].lchild);
		if (Node[now].rchild != -1)q.push(Node[now].rchild);
	}
}
int main() {
	int lchild, rchild;
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d %d", &lchild, &rchild);
		Node[i].lchild = lchild;
		Node[i].rchild = rchild;
	}
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &in[i]);
	}
	sort(in, in + n);
	inOrder(0);
	bfs(0);
	return 0;
}