//PAT_A 1107
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int father[maxn];
int isRoot[maxn] = { 0 };
int course[maxn] = { 0 };
int findFather(int x) {
	int a = x;
	while (x != father[x]) {
		x = father[x];
	}
	while (a != father[a]) {//路径压缩
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b) {//合并
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB)father[faA] = faB;
}
void init(int n) {
	for (int i = 1; i <= n; i++) {
		father[i] = i;
		isRoot[i] = false;
	}
}
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, k, h;
	(void)scanf("%d", &n);
	init(n);
	for (int i = 1; i <= n; i++) {
		(void)scanf("%d:", &k);
		for (int j = 0; j < k; j++) {
			(void)scanf("%d", &h);
			if (course[h] == 0)course[h] = i;//第一个喜欢h活动的为i
			Union(i, findFather(course[h]));//合并
		}
	}
	for (int i = 1; i <= n; i++) {
		isRoot[findFather(i)]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (isRoot[i] != 0)ans++;
	}
	printf("%d\n", ans);
	sort(isRoot + 1, isRoot + n + 1, cmp);
	for (int i = 1; i <= ans; i++) {
		printf("%d", isRoot[i]);
		if (i < ans)printf(" ");
		else printf("\n");
	}
}