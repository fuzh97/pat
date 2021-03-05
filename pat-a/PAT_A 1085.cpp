//PAT_A 1085    
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int main() {
	int n, p, a[maxn];
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int i = 0, j = 0, count = 1;
	while (i < n && j < n) {
		while (j < n && a[j] <= (long long)a[i] * p) {
			count = max(count, j - i + 1);
			j++;
		}
		i++;
	}
	printf("%d\n", count);
	return 0;
}
//二分查找
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int n, p, a[maxn];
int binarySearch(int i, long long x) {
	if (a[n - 1] <= x)return n;//所有数都不大与x。返回n
	int left = i + 1, right = n - 1, mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (a[mid] <= x)left = mid + 1;//说明第一个大于x的数在mid后面
		else right = mid;//说明第一个大于x的数在mid之前(含mid)
	}
	return left;
}
int main() {
	(void)scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int ans = 1;
	for (int i = 0; i < n; i++) {
		int j = binarySearch(i, (long long)a[i] * p);
		ans = max(ans, j - i);
	}
	printf("%d", ans);
	return 0;
}
//upper_bound()
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int n, p, a[maxn];
int main() {
	(void)scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int ans = 1;
	for (int i = 0; i < n; i++) {
		//upper_bound()返回从begin到end-1位置第一个大于num的数，返回地址，减去数组首地址，得到对应的下标
		//lower_bound()返回从begin到end-1位置第一个大于等于num的数，返回地址，减去数组首地址，得到对应的下标
		int j = upper_bound(a + i + 1, a + n, (long long)a[i] * p) - a;
		ans = max(ans, j - i);
	}
	printf("%d", ans);
	return 0;
}
//two pointers
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int main() {
	int n, p, a[maxn];
	(void)scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int i = 0, j = 0, count = 1;
	while (i < n && j < n) {
		while (j < n && a[j] <= (long long)a[i] * p) {
			count = max(count, j - i + 1);
			j++;
		}
		i++;
	}
	printf("%d\n", count);
	return 0;
}
