//PAT_A 1087
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int maxv = 210;
const int inf = 0x3fffffff;
int n, m, st, ed, G[maxv][maxv], weight[maxv];
int d[maxv], numPath = 0, maxW = 0;
double maxAvg = 0;
bool vis[maxv] = {false};
vector<int> pre[maxv];
vector<int> tempPath, path;
map<string, int> cityToIndex;
map<int, string> indexToCity;
void dijkstra(int s)
{
	fill(d, d + maxv, inf);
	d[s] = 0;
	for (int i = 0; i < n; i++)
	{
		int u = -1, MIN = inf;
		for (int j = 0; j < n; j++)
		{
			if (vis[j] == false && d[j] < MIN)
			{
				MIN = d[j];
				u = j;
			}
		}
		if (u == -1)
			return;
		vis[u] = true;
		for (int v = 0; v < n; v++)
		{
			if (vis[v] == false && G[u][v] != inf)
			{
				if (d[v] > d[u] + G[u][v])
				{
					d[v] = G[u][v] + d[u];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[v] == d[u] + G[u][v])
					pre[v].push_back(u);
			}
		}
	}
}
void dfs(int v)
{
	if (v == st)
	{
		tempPath.push_back(v);
		numPath++;
		int tempW = 0; //点权之和
		for (int i = tempPath.size() - 2; i >= 0; i--)
		{
			int id = tempPath[i];
			tempW += weight[id];
		}
		double tempAvg = 1.0 * tempW / (tempPath.size() - 1);
		if (tempW > maxW)
		{
			maxW = tempW;
			maxAvg = tempAvg;
			path = tempPath;
		}
		else if (tempW == maxW && tempAvg > maxAvg)
		{
			maxAvg = tempAvg;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++)
	{
		dfs(pre[v][i]);
	}
	tempPath.pop_back();
}
int main()
{
	string start, city1, city2;
	cin >> n >> m >> start;
	cityToIndex[start] = 0;
	indexToCity[0] = start;
	for (int i = 1; i < n; i++)
	{
		cin >> city1 >> weight[i];
		cityToIndex[city1] = i;
		indexToCity[i] = city1;
	}
	st = 0; //起点编号为0;
	fill(G[0], G[0] + maxv * maxv, inf);
	for (int i = 0; i < m; i++)
	{
		cin >> city1 >> city2;
		int c1 = cityToIndex[city1], c2 = cityToIndex[city2];
		cin >> G[c1][c2];
		G[c2][c1] = G[c1][c2];
	}
	dijkstra(0);
	int rom = cityToIndex["ROM"];
	dfs(rom);
	printf("%d %d %d %d\n", numPath, d[rom], maxW, (int)maxAvg);
	for (int i = path.size() - 1; i >= 0; i--)
	{
		cout << indexToCity[path[i]];
		if (i > 0)
			cout << "->";
		else
			cout << endl;
	}
	return 0;
}