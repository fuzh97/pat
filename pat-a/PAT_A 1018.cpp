//PAT_A 1018
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXV = 510;
const int INF = 1000000000;
int n, m, Cmax, Sp, numPath = 0, G[MAXV][MAXV], weight[MAXV];
int d[MAXV], minNeed = INF, minRemain = INF;//minNeed记录最少携带的数目，minRemain记录最少带回的数目
bool vis[MAXV] = { false };
vector<int>pre[MAXV];
vector<int>tempPath, path;
void Dijkstra(int s) {
	fill(d, d + MAXV, INF);
	d[s] = 0;
	for (int i = 0; i <= n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j <= n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)return;
		vis[u] = true;
		for (int v = 0; v <= n; v++) {
			if (vis[v] == false && G[u][v] != INF) {
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[v] == d[u] + G[u][v])pre[v].push_back(u);
			}
		}
	}
}
void DFS(int v) {
	if (v == 0) {
		tempPath.push_back(v);
		//计算最短路径标尺
		int need = 0, remain = 0;
		for (int i = tempPath.size() - 1; i >= 0; i--) {
			int id = tempPath[i];
			if (weight[id] > 0) {
				//如果当前节点点权为正，说明需要收走自行车，收走数量为点权值
				remain += weight[id];
			}
			else {
				//如果点权为负，则从前面收走的remain中向该节点投放自行车
				if (remain > abs(weight[id]))remain -= abs(weight[id]);
				else {
					//如果不够投放，需要从PBMC携带
					need += abs(weight[id]) - remain;
					remain = 0;//当前持有的自行车全部用来补给
				}
			}
		}
		if (need < minNeed) {//最短路径相同，选择需要从PBMC带的最少的情况
			minNeed = need;
			minRemain = remain;
			path = tempPath;
		}
		else if (need == minNeed && remain < minRemain) {//need还相同，选择remain少的情况
			minRemain = remain;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}
int main() {
	(void)scanf("%d %d %d %d", &Cmax, &n, &Sp, &m);
	int u, v;
	fill(G[0], G[0] + MAXV * MAXV, INF);
	for (int i = 1; i <= n; i++) {
		(void)scanf("%d", &weight[i]);
		weight[i] -= Cmax / 2;//点权减去容量的一半，计算距离prefect还差多少
	}
	for (int i = 0; i < m; i++) {
		(void)scanf("%d %d", &u, &v);
		(void)scanf("%d", &G[u][v]);
		G[v][u] = G[u][v];
	}
	Dijkstra(0);
	DFS(Sp);
	printf("%d ", minNeed);
	for (int i = path.size() - 1; i >= 0; i--) {
		//路径的顺序是倒序存放的
		printf("%d", path[i]);
		if (i > 0)printf("->");
	}
	printf(" %d", minRemain);
	return 0;
}