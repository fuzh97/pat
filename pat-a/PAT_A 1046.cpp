//PAT_A 1046
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int dis[maxn], A[maxn];
int main() {
	int sum = 0, query, n, left, right;
	(void)scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		(void)scanf("%d", &A[i]);
		sum += A[i];
		dis[i] = sum;
	}
	(void)scanf("%d", &query);
	for (int i = 0; i < query; i++) {
		(void)scanf("%d %d", &left, &right);
		if (left > right)swap(left, right);
		int temp = dis[right - 1] - dis[left - 1];
		printf("%d\n", min(temp, sum - temp));
	}
	return 0;
}