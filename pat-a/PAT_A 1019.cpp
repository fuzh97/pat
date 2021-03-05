//PAT_A 1019
#include<cstdio>
using namespace std;
int main() {
	int n, b, num = 0, ans[50];
	bool flag = true;
	(void)scanf("%d %d", &n, &b);
	do {
		ans[num++] = n % b;
		n /= b;
	} while (n != 0);
	for (int i = 0; i <= num / 2; i++) {
		if (ans[i] != ans[num - i - 1]) {
			flag = false;
			break;
		}
	}
	if (flag == true)printf("Yes\n");
	else printf("No\n");
	for (int i = num - 1; i >= 0; i--) {
		printf("%d", ans[i]);
		if (i != 0)printf(" ");
	}
	return 0;
}
