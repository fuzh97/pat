//PAT_A 1032
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100010;
struct node {
	char data;
	int next;
	bool flag;
}node[maxn];
int main() {
	for (int i = 0; i < maxn; i++) {
		node[i].flag = false;
	}
	int s1, s2, n;//两条链表首地址，节点个数
	(void)scanf("%d %d %d", &s1, &s2, &n);
	for (int i = 0; i < n; i++) {
		int address, next;
		char data;
		(void)scanf("%d", &address);
		(void)scanf("%c %d", &node[address].data, &node[address].next);
	}
	int p;
	for (p = s1; p != -1; p = node[p].next) {
		node[p].flag = true;
	}
	for (p = s2; p != -1; p = node[p].next) {
		if (node[p].flag == true) {
			printf("%05d", p);
			break;
		}
	}
	if (p == -1)printf("-1");
	return 0;
}