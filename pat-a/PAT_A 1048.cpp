//PAT_A 1048 Hash
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1005;
int HashTable[maxn];
int main() {
	int n, m, a;
	(void)scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &a);
		HashTable[a]++;
	}
	for (int i = 1; i < m; i++) {
		if (HashTable[i] && HashTable[m - i]) {
			if (i == m - i && HashTable[i] <= 1)continue;
			printf("%d %d\n", i, m - i);
			return 0;
		}
	}
	printf("No Solution\n");
	return 0;
}

//PAT_A 1048 二分
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100010];
int Bin(int left, int right, int key) {
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (a[mid] == key)return mid;
		else if (a[mid] > key)right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}
int main() {
	int i, n, m;
	bool flag = false;
	(void)scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (i = 0; i < n; i++) {
		int pos = Bin(0, n - 1, m - a[i]);
		if (pos != -1 && pos != i) {
			printf("%d %d\n", a[i], a[pos]);
			flag = true;
			break;
		}
	}
	if (flag == false)printf("No Solution");
	return 0;
}

//PAT_A 1048 二分 two pointers
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int main() {
	int n, m, a[maxn];
	(void)scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int i = 0, j = n - 1;
	while (i < j) {
		if (a[i] + a[j] == m)break;
		else if (a[i] + a[j] < m)i++;
		else j--;
	}
	if (i < j)printf("%d %d\n", a[i], a[j]);
	else printf("No Solution");
	return 0;
}