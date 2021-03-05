//PAT_A 1065
#include<cstdio>
using namespace std;
int main() {
	int T;
	long long a, b, c, res;
	bool flag;
	(void)scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		(void)scanf("%lld %lld %lld", &a, &b, &c);
		res = a + b;
		if (a > 0 && b > 0 && res <= 0)flag = true;//正向溢出 A+B>C
		else if (a < 0 && b < 0 && res >= 0)flag = false;//负向溢出 A+B<C
		else if (res > c)flag = true;
		else flag = false;
		if (flag == true)printf("Case #%d: true\n", i + 1);
		else if (flag == false)printf("Case #%d: false\n", i + 1);
	}
	return 0;
}
