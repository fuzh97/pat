//PAT_A 1021
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100010;
vector<int> G[maxn];//邻接表
bool isRoot[maxn];
int father[maxn];
int findFather(int x) {
	int a = x;
	while (x != father[x])x = father[x];
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB)father[faA] = faB;
}
void init(int n) {//初始化
	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}
}
int calBlock(int n) {
	int block = 0;
	for (int i = 1; i <= n; i++) {
		isRoot[findFather(i)] = true;
	}
	for (int i = 1; i <= n; i++) {
		block += isRoot[i];
	}
	return block;	
}
int maxH = 0;
vector<int> temp, ans;
void dfs(int u, int height, int pre) {//u 当前访问节点编号，height 当前树高，pre u的父亲节点
	if (height > maxH) {//更新最大高度
		temp.clear();
		temp.push_back(u);
		maxH = height;
	}
	else if (height == maxH)temp.push_back(u);
	for (int i = 0; i < G[u].size(); i++) {
		if (G[u][i] == pre)continue;//跳过回去的边
		dfs(G[u][i], height + 1, u);
	}
}
int main() {
	int a, b, n;
	(void)scanf("%d", &n);
	init(n);
	for (int i = 1; i < n; i++) {
		(void)scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
		Union(a, b);
	}
	int block = calBlock(n);
	if (block != 1) printf("Error: %d components\n", block);
	else {
		dfs(1, 1, -1);//从1号节点开始遍历
		ans = temp;
		dfs(ans[0], 1, -1);//从任意节点开始遍历
		for (int i = 0; i < temp.size(); i++) {
			ans.push_back(temp[i]);//取并集
		}
		sort(ans.begin(), ans.end());
		printf("%d\n", ans[0]);
		for (int i = 1; i < ans.size(); i++) {
			if (ans[i] != ans[i - 1])printf("%d\n", ans[i]);
		}
	}
	return 0;
}