//PAT_A 1064
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int n, number[maxn], cbt[maxn], index;
void inOrder(int root) {
	if (root > n)return;
	inOrder(2 * root);
	cbt[root] = number[index++];
	inOrder(2 * root + 1);
}
int main() {
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &number[i]);
	}
	sort(number, number + n);
	inOrder(1);
	for (int i = 1; i <= n; i++) {
		printf("%d", cbt[i]);
		if (i < n)printf(" ");
		else printf("\n");
	}
	return 0;
}