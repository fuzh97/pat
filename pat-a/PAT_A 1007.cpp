//PAT_A 1007
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 10010;
int main() {
	int n, k = 0;
	(void)scanf("%d", &n);
	vector<int> A(n), dp(n), s(n);
	bool flag = false;//标记是不是全部是负数
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &A[i]);
		if (A[i] >= 0)flag = true;
	}
	if (flag == false) {//特判 全负
		printf("0 %d %d\n", A[0], A[n - 1]);
		return 0;
	}
	dp[0] = A[0], s[0] = 0;
	for (int i = 1; i < n; i++) {
		if (A[i] > dp[i - 1] + A[i]) {
			dp[i] = A[i];
			s[i] = i;
		}
		else {
			dp[i] = A[i] + dp[i - 1];
			s[i] = s[i - 1];
		}
		if (dp[i] > dp[k])k = i;//保存最大值
	}
	printf("%d %d %d", dp[k], A[s[k]], A[k]);
	return 0;
}