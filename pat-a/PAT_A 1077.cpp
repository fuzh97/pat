//PAT_A 1077
#include<cstdio>
#include<cstring>
using namespace std;
int n, minLen = 256, ans = 0;//ans保存公共子串的长度
char s[110][256];
int main() {
	(void)scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		(void)scanf("%[^\n]", s[i]);
		getchar();
		int len = strlen(s[i]);
		if (len < minLen) minLen = len;//记录最小的串的长度，防止越界
		for (int j = 0; j < len / 2; j++) {
			char temp = s[i][j];
			s[i][j] = s[i][len - j - 1];
			s[i][len - j - 1] = temp;
		}
	}
	for (int i = 0; i < minLen; i++) {
		char c = s[0][i];
		bool same = true;
		for (int j = 1; j < n; j++) {
			if (c != s[j][i]) {
				same = false;
				break;
			}
		}
		if (same == true) ans++;//如果所有字符串的第i位相等，则计数器ans++。
		else break;
	}
	if (ans != 0) {
		for (int i = ans - 1; i >= 0; i--) {
			printf("%c", s[0][i]);
		}
	}
	else printf("nai");
	return 0;
}