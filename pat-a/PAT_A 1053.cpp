//PAT_A 1053
//vector保存路径
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 110;
struct node {
	int weight;
	vector<int> child;
}Node[maxn];
bool cmp(int a,int b) {
	return Node[a].weight > Node[b].weight;
}
int n, m, s;
vector<int> path;//保存路径
void dfs(int index, int sum) {
	if (sum > s)return;
	if (sum == s) {
		if (Node[index].child.size() != 0)return;
		for (int i = 0; i < path.size(); i++) {
			printf("%d", Node[path[i]].weight);
			if (i < path.size() - 1)printf(" ");
			else printf("\n");
		}
		return;
	}
	int t = Node[index].child.size();
	for (int i = 0; i < t; i++) {
		int child = Node[index].child[i];
		path.push_back(child);
		dfs(child, sum + Node[child].weight);
		path.pop_back();
	}
}
int main() {
	(void)scanf("%d %d %d", &n, &m, &s);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &Node[i].weight);
	}
	int id, k, child;
	for (int i = 0; i < m; i++) {
		(void)scanf("%d %d", &id, &k);
		for (int j = 0; j < k; j++) {
			(void)scanf("%d", &child);
			Node[id].child.push_back(child);
		}
		sort(Node[id].child.begin(), Node[id].child.end(), cmp);//节点从大到小排序
	}
	//path[0] = 0;
	path.push_back(0);//第一个节点
	dfs(0, Node[0].weight);
	return 0;
}

//数组保存路径
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 110;
struct node {
	int weight;
	vector<int> child;
}Node[maxn];
bool cmp(int a, int b) {
	return Node[a].weight > Node[b].weight;
}
int n, m, S;
int path[maxn];
void DFS(int index, int numNode, int sum) {
	if (sum > S)return;//权值超过叶子
	if (sum == S) {
		if (Node[index].child.size() != 0)return;//权值到了但是还没到叶子节点
		for (int i = 0; i < numNode; i++) {
			printf("%d", Node[path[i]].weight);
			if (i < numNode - 1)printf(" ");
			else printf("\n");
		}
		return;
	}
	for (int i = 0; i < Node[index].child.size(); i++) {//权值不到S
		int child = Node[index].child[i];
		path[numNode] = child;
		DFS(child, numNode + 1, sum + Node[child].weight);
	}
}
int main() {
	(void)scanf("%d %d %d", &n, &m, &S);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &Node[i].weight);
	}
	int id, k, child;
	for (int i = 0; i < m; i++) {
		(void)scanf("%d %d", &id, &k);
		for (int j = 0; j < k; j++) {
			(void)scanf("%d", &child);
			Node[id].child.push_back(child);
		}
		sort(Node[id].child.begin(), Node[id].child.end(), cmp);
	}
	path[0] = 0;
	DFS(0, 1, Node[0].weight);
	return 0;
}