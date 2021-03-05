//PAT_A 1002
#include<cstdio>
using namespace std;
const int maxn = 1111;
double p[maxn] = { 0 };
int main() {
	int k, n, count = 0;
	double a;
	(void)scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		(void)scanf("%d %lf", &n, &a);
		p[n] += a;
	}
	(void)scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		(void)scanf("%d %lf", &n, &a);
		p[n] += a;
	}
	for (int i = 0; i < maxn; i++) {
		if (p[i] != 0)count++;
	}
	printf("%d", count);
	for (int i = maxn - 1; i >= 0; i--) {
		if (p[i] != 0)printf(" %d %.1f", i, p[i]);
	}
	return 0;
}
