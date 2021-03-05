//PAT_A 1049
#include<cstdio>
using namespace std;
int main() {
	int n, a = 1, ans = 0;
	int left, right, now = 0;
	(void)scanf("%d", &n);
	while (n / a != 0) {
		left = n / (a * 10);
		now = n / a % 10;
		right = n % a;
		if (now == 0)ans += left * a;
		else if (now == 1)ans += left * a + right + 1;
		else ans += (left + 1) * a;
		a *= 10;
	}
	printf("%d", ans);
	return 0;
}