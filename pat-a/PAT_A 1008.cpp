//PAT_A 1008
#include<cstdio>
int main() {
	int n, total = 0, now = 0, to;
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &to);
		if (to > now)total += ((to - now) * 6);
		else total += ((now - to) * 4);
		total += 5;
		now = to;
	}
	printf("%d\n", total);
	return 0;
}