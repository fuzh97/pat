//PAT_A 1004
//dfs
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 110;
vector<int> G[maxn];
int leaf[maxn] = { 0 };//每层叶子节点的个数
int max_h = 1;//深度
void dfs(int index, int h) {
	max_h = max(max_h, h);
	if (G[index].size() == 0) {
		leaf[h]++;
		return;
	}
	for (int i = 0; i < G[index].size(); i++) {
		dfs(G[index][i], h + 1);
	}
}
int main() {
	int n, m, parent, child, k;
	(void)scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		(void)scanf("%d %d", &parent, &k);
		for (int j = 0; j < k; j++) {
			(void)scanf("%d", &child);
			G[parent].push_back(child);
		}
	}
	dfs(1, 1);
	printf("%d", leaf[1]);
	for (int i = 2; i <= max_h; i++)printf(" %d", leaf[i]);
	return 0;
}

//bfs
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 110;
struct Node{
	int level;
	vector<int> child;
}node[maxn];
int leaf[maxn] = { 0 }, max_h = 0;
void bfs(int root) {
	queue<int> q;
	node[root].level = 1;
	q.push(root);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		if (node[temp].child.size() == 0) {
			leaf[node[temp].level]++;
			if (node[temp].level > max_h)max_h = node[temp].level;
		}
		else {
			for (int i = 0; i < node[temp].child.size(); i++) {
				int t = node[temp].child[i];
				node[t].level = node[temp].level + 1;
				q.push(node[temp].child[i]);
			}
		}
	}
}
int main() {
	int n, m;
	(void)scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int parent, child, k;
		(void)scanf("%d %d", &parent, &k);
		for (int j = 0; j < k; j++) {
			(void)scanf("%d", &child);
			node[parent].child.push_back(child);
		}
	}
	bfs(1);
	for (int i = 1; i <= max_h; i++) {
		printf("%d", leaf[i]);
		if (i < max_h)printf(" ");
		else printf("\n");
	}
	return 0;
}