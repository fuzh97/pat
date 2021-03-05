//PAT_A 1001
#include<cstdio>
#include<cstring>
using namespace std;
int num[10];
int main() {
	int a, b, sum;
	(void)scanf("%d %d", &a, &b);
	sum = a + b;
	if (sum < 0) {
		printf("-");
		sum = -sum;
	}
	int len = 0;
	if (sum == 0)num[len++] = 0;//sum保存在数组中，sum为0时特殊处理
	while (sum != 0) {
		num[len++] = sum % 10;
		sum /= 10;
	}
	for (int i = len - 1; i >= 0; i--) {
		printf("%d", num[i]);
		if (i > 0 && i % 3 == 0)printf(",");//每遇到i%3==0输出一个逗号，最后一组不用
	}
	return 0;
}