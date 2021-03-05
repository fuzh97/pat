//PAT_A 1059
#include<cstdio>
#include<cmath>
const int maxn = 100010;
bool isPrime(int n) {
	if (n <= 1)return false;
	int sqr = (int)sqrt(1.0 * n);
	for (int i = 2; i <= sqr; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
int Prime[maxn], PNum = 0;
void findPrime() {//1-maxn以内的素数表
	for (int i = 1; i < maxn; i++) {
		if (isPrime(i) == true)Prime[PNum++] = i;
	}
}
struct  factor{
	int x, cnt;
}fac[10];
int main() {
	findPrime();
	int n, num = 0;
	(void)scanf("%d", &n);
	if (n == 1) {
		printf("1=1");
		return 0;
	}
	printf("%d=", n);
	int sqr = (int)sqrt(1.0 * n);
	for (int i = 0; i < PNum && Prime[i] <= sqr; i++) {//在根号N之内的素数作为质因子
		if (n % Prime[i] == 0) {//Prime[i]是n的质因子
			fac[num].x = Prime[i];
			fac[num].cnt = 0;
			while (n % Prime[i] == 0) {
				fac[num].cnt++;
				n /= Prime[i];
			}
			num++;
		}
		if (n == 1)break;
	}
	if (n != 1) {//如果存在大于根号N的质因子，只可能有一个
		fac[num].x = n;
		fac[num].cnt = 1;
		num++;
	}
	for (int i = 0; i < num; i++) {
		if (i > 0)printf("*");
		printf("%d", fac[i].x);
		if (fac[i].cnt > 1)printf("^%d", fac[i].cnt);
	}
	return 0;
}