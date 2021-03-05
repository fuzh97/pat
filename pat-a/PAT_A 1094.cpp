//PAT_A 1094
//dfs实现
#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 110;
vector<int> Node[maxn];
int hashTable[maxn] = { 0 };
void DFS(int index, int level) {
	hashTable[level]++;
	for (int i = 0; i < Node[index].size(); i++) {
		DFS(Node[index][i], level + 1);
	}
}
int main() {	
	int n, m, parent, k, child;
	(void)scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		(void)scanf("%d %d", &parent, &k);
		for (int j = 0; j < k; j++) {
			(void)scanf("%d", &child);
			Node[parent].push_back(child);
		}
	}
	DFS(1, 1);
	int maxLevel = -1, maxValue = 0;
	for (int i = 1; i < maxn; i++) {
		if (hashTable[i] > maxLevel) {
			maxValue = hashTable[i];
			maxLevel = i;
		}
	}
	printf("%d %d\n", maxValue, maxLevel);
	return 0;
}
```

//PAT_A 1094
//bfs实现
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 110;
int hashTable[maxn] = { 0 };
struct node {
	int layer;
	vector<int> child;
}Node[maxn];
void BFS(int root) {
	queue<int> q;
	Node[root].layer = 1;
	hashTable[Node[root].layer]++;
	q.push(root);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 0; i < Node[front].child.size(); i++) {
			int child = Node[front].child[i];
			Node[child].layer = Node[front].layer + 1;
			hashTable[Node[child].layer]++;
			q.push(child);
		}
	}
}
int main() {
	int n, m, parent, k, child;
	(void)scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		(void)scanf("%d %d", &parent, &k);
		for (int j = 0; j < k; j++) {
			(void)scanf("%d", &child);
			Node[parent].child.push_back(child);
		}
	}
	BFS(1);
	int maxLevel = -1, maxValue = 0;
	for (int i = 1; i < maxn; i++) {
		if (hashTable[i] > maxValue) {
			maxValue = hashTable[i];
			maxLevel = i;
		}
	}
	printf("%d %d\n", maxValue, maxLevel);
	return 0;
}