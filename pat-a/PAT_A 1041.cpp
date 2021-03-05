//PAT_A 1041
#include<cstdio>
#include<cstring>
using namespace std;
int a[100001], hashTable[100001] = { 0 };
int main() {
	int n;
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &a[i]);
		hashTable[a[i]]++;
	}
	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (hashTable[a[i]] == 1) {
			ans = a[i];
			break;
		}
	}
	if (ans == -1)printf("None");
	else printf("%d\n", ans);
	return 0;
}