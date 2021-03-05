//PAT_A 1096
#include<cstdio>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int main() {
	ll n, ansI = 0, ansLen = 0;
	(void)scanf("%lld", &n);
	ll sqr = (ll)sqrt((1.0) * n);
	for (ll i = 2; i <= sqr; i++) {
		ll temp = 1, j = i;
		while (true) {
			temp *= j;
			if (n % temp != 0)break;
			if (j - i + 1 > ansLen) {
				ansLen = j - i + 1;
				ansI = i;
			}
			j++;
		}
	}
	if (ansLen == 0)printf("1\n%lld\n", n);
	else {
		printf("%lld\n", ansLen);
		for (ll i = 0; i < ansLen; i++) {
			printf("%lld", ansI + i);
			if (i < ansLen - 1)printf("*");
		}
	}
	return 0;
}