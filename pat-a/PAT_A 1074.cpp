//PAT_A 1074
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
struct Node{
	int address, data, next;
	int order;
}node[maxn];
bool cmp(Node a, Node b) {
	return a.order < b.order;
}
int main() {
	for (int i = 0; i < maxn; i++) {
		node[i].order = maxn;
	 }
	int begin, n, address, k;
	(void)scanf("%d %d %d", &begin, &n, &k);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &address);
		(void)scanf("%d %d", &node[address].data, &node[address].next);
		node[address].address = address;
	}
	int p = begin, count = 0;//有效节点的数目
	while (p != -1) {
		node[p].order = count++;
		p = node[p].next;
	}
	sort(node, node + maxn, cmp);
	n = count;
	for (int i = 0; i < n/k; i++) {
		for (int j = (i + 1) * k - 1; j > i* k; j--) {//第i块倒序输出
			printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
		}
		printf("%05d %d ", node[i * k].address, node[i * k].data);
		if (i < n / k - 1) {//不是最后一块 指向下一块最后一个节点
			printf("%05d\n", node[(i + 2) * k - 1].address);
		}
		else {//是最后一块
			if (n % k == 0)printf("-1");//没有尾巴
			else {
				printf("%05d\n", node[(i + 1) * k].address);//按原先顺序输出
				for (int l = n / k * k; l < n; l++) {
					printf("%05d %d ", node[l].address, node[l].data);
					if (l < n - 1)printf("%05d\n", node[i + 1].address);
					else printf("-1");
				}
				
			}
		}
	}
	return 0;
}