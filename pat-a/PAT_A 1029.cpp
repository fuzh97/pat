//PAT_A 1029
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1000010;
const int INF = 0x7fffffff;
int s1[maxn], s2[maxn];
int main() {
	int n, m;
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &s1[i]);
	}
	(void)scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		(void)scanf("%d", &s2[i]);
	}
	s1[n] = s2[m] = INF;//两序列最后一个元素设为INF
	int mid = (n + m - 1) / 2;//中位数位置
	int i = 0, j = 0, count = 0;
	while (count < mid) {
		if (s1[i] < s2[j])i++;
		else j++;
		count++;
	}
	printf("%d\n", min(s1[i],s2[j]));
	return 0;
}