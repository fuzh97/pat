//PAT_A 1015
#include<cstdio>
#include<cmath>
using namespace std;
bool isPrime(int n) {
	if (n <= 1)return false;
	int sqr = (int)sqrt(n * 1.0);
	for (int i = 2; i <= sqr; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
int d[111];
int reverse_radix(int n, int radix) {//将n转换为radix进制反转之后再返回
	int len = 0, ans = 0;
	while (n != 0) {
		d[len++] = n % radix;
		n /= radix;
	}
	for (int i = 0; i < len; i++) {
		ans = ans * radix + d[i];;
	}
	return ans;
}
int main() {
	int n, radix;
	while (scanf("%d", &n) != EOF) {
		if (n < 0)break;
		(void)scanf("%d", &radix);
		if (isPrime(n) == false)printf("No\n");
		else {
			int temp = reverse_radix(n, radix);
			if (isPrime(temp) == true)printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}