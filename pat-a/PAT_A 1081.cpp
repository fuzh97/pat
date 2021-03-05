//PAT_A 1081
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
struct  Fraction{
	LL up, down;
	Fraction() {};
	Fraction(LL _up, LL _down) {
		up = _up;
		down = _down;
	}
};
LL gcd(LL a, LL b) {//最大公约数
	if (b == 0)return a;
	else return gcd(b, a % b);
}
Fraction reduction(Fraction result) {//化简
	if (result.down < 0) {
		result.up = -result.up;
		result.down = -result.down;
	}
	if (result.up == 0)result.down = 1;//分子为0，令分母为1
	else {
		int d = gcd(result.down, result.up);
		result.down /= d;
		result.up /= d;
	}
	return result;
}
Fraction add(Fraction a, Fraction b) {
	Fraction result;
	result.up = a.up * b.down + b.up * a.down;
	result.down = a.down * b.down;
	return reduction(result);
}
void showResult(Fraction a) {
	//reduction(a);
	if (a.down == 1)printf("%lld\n", a.up);
	else if (abs(a.up) > a.down) {
		printf("%lld %lld/%lld\n", a.up / a.down, abs(a.up) % a.down, a.down);
	}
	else printf("%lld/%lld", a.up, a.down);
}
int main() {
	int n;
	(void)scanf("%d", &n);
	Fraction sum(0, 1), temp;
	for (int i = 0; i < n; i++) {
		(void)scanf("%lld/%lld", &temp.up, &temp.down);
		sum = add(sum, temp);
	}
	showResult(sum);
	return 0;
}
