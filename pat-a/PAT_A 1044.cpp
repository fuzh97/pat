//PAT_A 1044
#include<cstdio>
const int N = 100010;
int sum[N];
int n, S, nearS = 100000010;//NearS大于等于S的最接近S的和值
int upper_bound(int L, int R, int x) {//寻找第一个大于X的位置
	int left = L, right = R, mid;
	while (left < right) {
		mid = (right + left) / 2;
		if (sum[mid] > x)right = mid;
		else left = mid + 1;
	}
	return left;
}
int main() {
	(void)scanf("%d %d", &n, &S);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		(void)scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}
	for (int i = 1; i <= n; i++) {//第一次循环，找见nearS
		int j = upper_bound(i, n + 1, sum[i - 1] + S);//Sum[j]-sum[i-1]=S=>Sum[j]=S+sum[i-1]
		if (sum[j - 1] - sum[i - 1] == S) {//查找成功，Sum[j]为第一个大于S的元素，则Sum[j-1]为最后一个大于等于S的元素
			nearS = S;
			break;
		}
		else if (j <= n && sum[j] - sum[i - 1] < nearS) {//存在大于S的解并小于nearS
			nearS = sum[j] - sum[i - 1];
		}
	}
	for (int i = 1; i <= n; i++) {//第二次循环 保证先输出左断点较小的元素
		int j = upper_bound(i, n + 1, sum[i - 1] + nearS); 
		if (sum[j - 1] - sum[i - 1] == nearS) {
			printf("%d-%d\n", i, j - 1);
		}
	}
	return 0;
}