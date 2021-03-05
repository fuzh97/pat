//PAT_A 1079
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int maxn = 100010;
struct  node{
	double data;
	vector<int> child;
}Node[maxn];
int n;
double p, r, ans;
void dfs(int index, int depth) {
	if (Node[index].child.size() == 0) {
		ans += Node[index].data * pow(1 + r, depth);
		return;
	}
	for (int i = 0; i < Node[index].child.size(); i++) {
		dfs(Node[index].child[i], depth + 1);
	}
}
int main() {
	int k, child;
	(void)scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &k);
		if (k == 0) {
			(void)scanf("%lf", &Node[i].data);//叶节点的存货量
		}
		else {
			for (int j = 0; j < k; j++) {
				(void)scanf("%d", &child);
				Node[i].child.push_back(child);
			}
		}
	}
	dfs(0, 0);
	printf("%.1f\n", p * ans);
	return 0;
}