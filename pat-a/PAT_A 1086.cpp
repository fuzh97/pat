//PAT_A 1086
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 50;
struct node {
	int data;
	node* lchild;
	node* rchild;
};
int pre[maxn], in[maxn], post[maxn];
int n;
node* creat(int preL, int preR, int inL, int inR) {
	if (preL > preR)return NULL;
	node* root = new node;
	root->data = pre[preL];
	int k;
	for (k = inL; k <= inR; k++) {
		if (in[k] == root->data)break;
	}
	int numLeft = k - inL;
	root->lchild = creat(preL + 1, preL + numLeft, inL, k - 1);
	root->rchild = creat(preL + numLeft + 1, preR, k + 1, inR);
	return root;
}
int num = 0;
void postOrder(node* root) {
	if (root == NULL)return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d", root->data);
	num++;
	if (num < n)printf(" ");
}
int main() {
	(void)scanf("%d", &n);
	char str[5];
	stack<int> st;
	int x, preIndex = 0, inIndex = 0;
	for (int i = 0; i < 2 * n; i++) {
		(void)scanf("%s", str);
		if (strcmp(str, "Push") == 0) {
			(void)scanf("%d", &x);
			st.push(x);
			pre[preIndex++] = x;
		}
		else {
			in[inIndex++] = st.top();
			st.pop();
		}
	}
	node* root = creat(0, n - 1, 0, n - 1);
	postOrder(root);
	return 0;
}