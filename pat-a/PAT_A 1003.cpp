//PAT_A 1003
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int maxv = 510;
const int INF = 0x3fffffff;
int n, m, st, ed, G[maxv][maxv], weight[maxv], d[maxv];
int numPath = 0;//路径条数
int maxw = 0;//最大点权
bool vis[maxv] = { false };
vector<int> pre[maxv];
vector<int> tempPath, path;
void Dijkstra(int s) {
	fill(d, d + maxv, INF);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, min = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < min) {
				min = d[j];
				u = j;
			}
		}
		if (u == -1)return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (d[v] > d[u] + G[u][v]) {
				d[v] = d[u] + G[u][v];
				pre[v].clear();
				pre[v].push_back(u);
			}
			else if (d[v] == G[u][v] + d[u])pre[v].push_back(u);
		}
	}
}
void dfs(int v) {
	if (v == st) {
		numPath++;
		int tempW = 0;
		tempPath.push_back(v);
		for (int i = tempPath.size() - 1; i >= 0; i--) {
			int id = tempPath[i];
			tempW += weight[id];
		}
		if (tempW > maxw) {
			maxw = tempW;
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
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &weight[i]);
	}
	int u, v;
	fill(G[0], G[0] + maxv * maxv, INF);
	for (int i = 0; i < m; i++) {
		(void)scanf("%d %d", &u, &v);
		(void)scanf("%d", &G[u][v]);
		G[v][u] = G[u][v];
	}
	Dijkstra(st);
	dfs(ed);
	printf("%d %d\n", numPath, maxw);
	return 0;
}