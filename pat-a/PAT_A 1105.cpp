//PAT_A 1105
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 10010;
int matrix[maxn][maxn], A[maxn];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int N, m, n;
	(void)scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		(void)scanf("%d", &A[i]);
	}
	if (N == 1) {
		printf("%d", A[0]);
		return 0;
	}
	sort(A, A + N, cmp);
	m = (int)ceil(sqrt(1.0 * N));
	while (N % m != 0)m++;
	n = N / m;
	int u = 1, d = m, l = 1, r = n;//边界
	int i = 1, j = 1, now = 0;
	while (now < N) {
		while (now < N && j < r) {//向右
			matrix[i][j] = A[now++];
			j++;
		}
		while (now < N && i < d) {//向下
			matrix[i][j] = A[now++];
			i++;
		}
		while (now < N && j > l) {//向左
			matrix[i][j] = A[now++];
			j--;
		}
		while (now < N && i > u) {//向上
			matrix[i][j] = A[now++];
			i--;
		}
		i++; j++; u++; d--; l++; r--;//缩小边界，移动指针
		if (now == N - 1)matrix[i][j] = A[now++];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d", matrix[i][j]);
			if (j < n)printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
