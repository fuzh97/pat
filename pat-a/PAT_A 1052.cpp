//PAT_A 1052
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100010;
struct  Node{
	int address, data, next;
	bool flag;
}node[maxn];
bool cmp(Node a, Node b) {
	if (a.flag == false || b.flag == false)return a.flag > b.flag;
	else return a.data < b.data;
}
int main() {
	for (int i = 0; i < maxn; i++) {
		node[i].flag = false;
	}
	int n, begin, address;
	(void)scanf("%d %d", &n, &begin);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &address);
		node[address].address = address;
		(void)scanf("%d %d", &node[address].data, &node[address].next);
	}
	int count = 0, p = begin;
	while (p != -1) {
		node[p].flag == true;
		p = node[p].next;
		count++;
	}
	if (count == 0)printf("0 -1\n");
	else {
		sort(node, node + maxn, cmp);
		printf("%d %05d", count, node[0].address);
		for (int i = 0; i < count; i++) {
			printf("%05d %d ", node[i].address, node[i].data);
			if (i < count - 1) printf("%05d\n", node[i + 1].address);
			else printf("-1\n");
		}
	}
	return 0;
}