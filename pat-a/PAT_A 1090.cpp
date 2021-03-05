//PAT_A 1090
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int maxn = 100010;
vector<int> child[maxn];
double p, r;
int n, maxDepth = 0, num = 0;
void dfs(int index, int depth) {
	if (child[index].size() == 0) {
		if (depth > maxDepth) {
			maxDepth = depth;
			num = 1;
		}
		else if (depth == maxDepth)num++;
		return;
	}
	for (int i = 0; i < child[index].size(); i++) {
		dfs(child[index][i], depth + 1);
	}
}
int main() {
	int father, root;
	(void)scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &father);
		if (father != -1) {
			child[father].push_back(i);
		}
		else root = i;
	}
	dfs(root, 0);
	printf("%.2f %d\n", p * pow(1 + r, maxDepth), num);
	return 0;
}
