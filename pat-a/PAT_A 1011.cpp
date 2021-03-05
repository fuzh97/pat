//PAT_A 1011
#include<cstdio>
using namespace std;
char S[3] = { 'W','T','L' };
int main() {
	double ans = 1, temp, a;
	int idx;
	for (int i = 0; i < 3; i++) {
		temp = 0;
		for (int j = 0; j < 3; j++) {
			(void)scanf("%lf", &a);
			if (a > temp) {
				temp = a;
				idx = j;
			}
		}
		ans *= temp;
		printf("%c ", S[idx]);
	}
	printf("%.2f", (ans * 0.65 - 1) * 2);
	return 0;
}