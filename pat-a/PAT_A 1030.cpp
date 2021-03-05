//PAT_A 1030
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxv = 510;
const int inf = 0x3fffffff;
int n, m, st, ed, G[maxv][maxv], cost[maxv][maxv];
int d[maxv], minCost = inf;
bool vis[maxv] = { false };
vector<int> pre[maxv];
vector<int> path, tempPath;
void dijkstra(int s) {
	fill(d, d + maxv, inf);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = inf;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				MIN = d[j];
				u = j;
			}
		}
		if (u == -1)return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (vis[v] == false && G[u][v] != inf) {
				if (d[v] > d[u] + G[u][v]) {
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[v] == d[u] + G[u][v])pre[v].push_back(u);
			}
		}
	}
}
void dfs(int v) {
	if (v == st) {
		tempPath.push_back(v);
		int tempCost = 0;
		for (int i = tempPath.size() - 1; i > 0; i--) {
			int id = tempPath[i];
			int idNext = tempPath[i - 1];
			tempCost += cost[id][idNext];
		}
		if (tempCost < minCost) {
			minCost = tempCost;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		dfs(pre[v][i]);
	}
	tempPath.pop_back();
}
int main() {
	(void)scanf("%d %d %d %d", &n, &m, &st, &ed);
	int u, v;
	fill(G[0], G[0] + maxv * maxv, inf);//G[0]是二维数组的首地址即G[0][0]的地址
	fill(cost[0], cost[0] + maxv * maxv, inf);
	for (int i = 0; i < m; i++) {
		(void)scanf("%d %d", &u, &v);
		(void)scanf("%d %d", &G[u][v], &cost[u][v]);
		G[v][u] = G[u][v];
		cost[v][u] = cost[u][v];
	}
	dijkstra(st);
	dfs(ed);
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
	printf("%d %d\n", d[ed], minCost);
	return 0;
}
