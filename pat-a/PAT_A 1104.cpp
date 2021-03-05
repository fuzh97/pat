//PAT_A 1104
#include<cstdio>
using namespace std;
int main() {
	int n;
	double v, ans = 0;
	(void)scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		(void)scanf("%lf", &v);
		ans += v * i * (n - i + 1);
	}
	printf("%.2f", ans);
	return 0;
}