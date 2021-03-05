//PAT_A 1045
//最长不下降子序列LIS
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 210;
const int maxc = 10010;
int hashTable[maxn];
int A[maxc], dp[maxc];
int main() {
	int n, m, x;
	(void)scanf("%d %d", &n, &m);
	fill(hashTable, hashTable + maxn, -1);
	for (int i = 1; i <= m; i++) {
		(void)scanf("%d", &x);
		hashTable[x] = i;//喜爱的颜色映射成为0~n-1
	}
	int L, num = 0;
	(void)scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		(void)scanf("%d", &x);
		if (hashTable[x] > 0) {//剔除掉不喜欢颜色的序列
			A[num++] = hashTable[x];//A中存储映射之后的键值
		}
	}
	int ans = 0;
	for (int i = 0; i < num; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[i] >= A[j])dp[i] = max(dp[i], dp[j] + 1);
		}
		if (dp[i] > ans)ans = dp[i];
	}
	printf("%d\n", ans);
	return 0;
}
//PAT_A 1045
//最长公共子序列 LCS
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxc = 210;
const int maxn = 10010;
int a[maxc], b[maxn], dp[maxc][maxn];
int main() {
	int n, m, l;
	(void)scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		(void)scanf("%d", &a[i]);
	}
	(void)scanf("%d", &l);
	for (int j = 1; j <= l; j++) {
		(void)scanf("%d", &b[j]);
	}
	for (int i = 0; i <= m; i++) {
		dp[i][0] = 0;
	}
	for (int i = 0; i <= l; i++) {
		dp[0][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= l; j++) {
			if (a[i] == b[j])dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	printf("%d\n", dp[m][l]);
	return 0;
}