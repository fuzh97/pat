//PAT_A 1093
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100010;
const int MOD = 1000000007;
char str[maxn];
int leftNumP[maxn] = { 0 };//每一位左边字母P的个数（含当前位）
int main() {
	(void)scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (i > 0) leftNumP[i] = leftNumP[i - 1];//不是首位的话继承上一位的值
		if (str[i] == 'P')leftNumP[i]++;//如果是P，加1
	}
	int ans = 0, rightNumT = 0;
	for (int i = len - 1; i >= 0; i--) {
		if (str[i] == 'T')rightNumT++;
		else if (str[i] == 'A')ans = (ans + rightNumT * leftNumP[i]) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}
