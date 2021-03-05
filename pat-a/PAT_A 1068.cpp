//PAT_A 1068
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10010;
const int maxv = 110;
int w[maxn], dp[maxn][maxv] = { 0 };
bool choice[maxn][maxv], flag[maxn];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, m;
	(void)scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		(void)scanf("%d", &w[i]);
	}
	sort(w + 1, w + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		for (int v = w[i]; v <= m; v++) {
			int temp1 = dp[i - 1][v - w[i]] + w[i];//放
			int temp2 = dp[i - 1][v];//不放
			if (temp1 >= temp2) {//保证字典序，如果相等也要选
				choice[i][v] = 1;//选i号硬币
				dp[i][v] = temp1;
			}
			else {
				choice[i][v] = 0;//不选i号硬币
				dp[i][v] = temp2;
			}
		}
	}
	if (dp[n][m] != m)printf("No Solution");
	else {
		int k = n, num = 0, v = m;//看choice数组的第v列
		while (k >= 0) {
			if (choice[k][v] == 1) {
				flag[k] = true;
				v -= w[k];
				num++;
			}
			else flag[k] = false;
			k--;
		}
		for (int i = n; i >= 1; i--) {
			if (flag[i] == true) {
				printf("%d", w[i]);
				num--;
				if (num > 0)printf(" ");
			}
		}
	}
	return 0;
}