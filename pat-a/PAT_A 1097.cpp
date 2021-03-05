//PAT_A 1097
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100010;
struct Node {
	int address, data, next;
	bool order;
}node[maxn];
bool isExist[maxn] = { false };
bool cmp(Node a, Node b) {
	return a.order < b.order;
}
int main() {
	memset(isExist, false, sizeof(isExist));
	for (int i = 0; i < maxn; i++) {
		node[i].order = 2 * maxn;
	}
	int n, begin, address;
	(void)scanf("%d %d", &begin, &n);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &address);
		(void)scanf("%d %d", &node[address].data, &node[i].next);
		node[address].address = address;
	}
	int countValid = 0, countRemoved = 0, p = begin;
	while (p != -1) {
		if (!isExist[abs(node[p].data)]) {//绝对值还没有出现过
			isExist[abs(node[p].data)] = true;
			node[p].order = countValid++;
		}
		else {
			node[p].order = countRemoved + maxn;
			countRemoved++;
		}
		p = node[p].next;
	}
	sort(node, node + maxn, cmp);
	int count = countRemoved + countValid;
	for (int i = 0; i < count; i++) {
		if (i != countValid - 1 && i != count - 1) {
			printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
		}
		else printf("%05d %d -1\n", node[i].address, node[i].data);
	}
	return 0;
}
