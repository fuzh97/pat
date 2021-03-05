//PAT_A 1072
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxv = 1020;
const int inf = 0x3fffffff;
int n, m, k, ds, G[maxv][maxv];
bool vis[maxv] = { false };
int d[maxv];
void dijkstra(int s) {
	fill(vis, vis + maxv, false);
	fill(d, d + maxv, inf);
	d[s] = 0;
	for (int i = 0; i < n + m; i++) {
		int u = -1, MIN = inf;
		for (int j = 1; j <= n + m; j++) {
			if (vis[j] == false && d[j] < MIN) {
				MIN = d[j];
				u = j;
			}
		}
		if (u == -1)return;
		vis[u] = true;
		for (int v = 1; v <= n + m; v++) {
			if (vis[v] == false && G[u][v] != inf) {
				if (d[v] > d[u] + G[u][v]) {
					d[v] = d[u] + G[u][v];
				}
			}
		}
	}
}
int getID(char str[]) {
	int i = 0, len = strlen(str), id = 0;
	while (i < len) {
		if (str[i] != 'G') {
			id = id * 10 + (str[i] - '0');
		}
		i++;
	}
	if (str[0] == 'G')return n + id;//加油站排在居民房的后面
	else return id;
}
int main() {
	(void)scanf("%d %d %d %d", &n, &m, &k, &ds);
	int u, v, w;
	char city1[5], city2[5];
	fill(G[0], G[0] + maxv * maxv, inf);
	for (int i = 0; i < k; i++) {
		(void)scanf("%s %s %d", city1, city2, &w);
		u = getID(city1), v = getID(city2);
		G[u][v] = w;
		G[v][u] = w;
	}
	double ansDis = -1, ansAvg = inf;//最短距离，最短平均距离
	int ansID = -1;//最终加油站
	for (int i = n + 1; i <= n + m; i++) {
		double minDis = inf, avg = 0;
		dijkstra(i);
		for (int j = 1; j <= n; j++) {
			if (d[j] > ds) {
				minDis = -1;
				break;
			}
			if (d[j] < minDis)minDis = d[j];
			avg += 1.0 * d[j] / n;
		}
		if (minDis == -1)continue;
		if (minDis > ansDis) {//优先输出最短距离最大的
			ansID = i;
			ansDis = minDis;
			ansAvg = avg;
		}
		else if (minDis == ansDis && avg < ansAvg) {//最短距离相同，输出平均距离最小的
			ansID = i;
			ansAvg = avg;
		}
	}
	if (ansID == -1)printf("No Solution\n");
	else {
		printf("G%d\n", ansID - n);
		printf("%.1f %.1f", ansDis, ansAvg);
	}
	return 0;
}