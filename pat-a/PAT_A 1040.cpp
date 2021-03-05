//PAT_A 1040
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1010;
char s[maxn];
int dp[maxn][maxn];
int main() {
	(void)scanf("%[^\n]", s);
	int len = strlen(s), ans = 1;
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < len; i++) {
		dp[i][i] = 1;//长度为1的子串
		if (i < len - 1) {
			if (s[i] == s[i + 1]) {//长度为2的子串
				dp[i][i + 1] = 1;
				ans = 2;//最长回文子串
			}
		}
	}
	for (int l = 3; l <= len; l++) {
		for (int i = 0; i + l - 1 < len; i++) {//枚举左串的起始顶点
			int j = i + l - 1;//右端点
			if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
				dp[i][j] = 1;
				ans = l;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}