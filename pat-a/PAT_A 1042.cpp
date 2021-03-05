//PAT_A 1042
#include<cstdio>
using namespace std;
const int N = 54;
char mp[5] = { 'S','H','C','D','J' };
int start[N + 1], end[N + 1], next[N + 1];
int main() {
	int k;//shuffles times;
	(void)scanf("%d", &k);
	for (int i = 1; i <= N; i++) {
		start[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		(void)scanf("%d", &next[i]);
	}
	for (int step = 0; step < k; step++) {
		for (int i = 1; i <= N; i++) {
			end[next[i]] = start[i];
		}
		for (int i = 1; i <= N; i++) {
			start[i] = end[i];
		}
	}
	//输出
	for (int i = 1; i <= N; i++) {
		if (start[i] % 13 == 0) {
			printf("%c%d", mp[start[i] / 13 - 1], 13);
		}
		else printf("%c%d", mp[start[i] / 13], start[i] % 13);
		if (i < N)printf(" ");
	}
	return 0;
}