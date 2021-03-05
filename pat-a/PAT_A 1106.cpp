//PAT_A 1106
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int maxn = 100010;
const double INF = 1e12;//10^12
vector<int> Node[maxn];
int n, num = 0;
double p, r, ans = INF, minDepth = INF;
void dfs(int index, int depth) {
	if (Node[index].size() == 0) {
		if (depth < minDepth) {
			minDepth = depth;
			num = 1;
		}
		else if (minDepth == depth)num++;
		return;
	}
	for (int i = 0; i < Node[index].size(); i++) {
		dfs(Node[index][i], depth + 1);
	}
}
int main() {
	int k, child;
	(void)scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &k);
		if (k != 0) {
			for (int j = 0; j < k; j++) {
				(void)scanf("%d", &child);
				Node[i].push_back(child);
			}
		}
	}
	dfs(0, 0);
	ans = p * pow(1 + r, minDepth);
	printf("%.4f %d\n", ans, num);
	return 0;
}