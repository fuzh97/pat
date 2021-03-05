//PAT_A 1009
#include<cstdio>
using namespace std;
int main() {
	int m, n, exp, count = 0;
	double cof, a[1010] = { 0 }, ans[2020] = { 0 };//ans存放答案 
	(void)scanf("%d", &m);//第一个多项式中非0项个数 
	for (int i = 0; i < m; i++) {
		(void)scanf("%d %lf", &exp, &cof);
		a[exp] += cof;
	}
	(void)scanf("%d", &n);//第二个多项式中的非0项个数
	for (int i = 0; i < n; i++) {
		(void)scanf("%d %lf", &exp, &cof);
		for (int j = 0; j < 1010; j++) {
			ans[exp + j] += (cof * a[j]);
		}
		
	}
	for (int i = 0; i < 2020; i++) {
		if (ans[i] != 0.0)count++;
	}
	printf("%d", count);
	for (int i = 2000; i >= 0; i--) {
		if (ans[i] != 0.0)printf(" %d %.1f", i, ans[i]);
	}
	return 0;
}
