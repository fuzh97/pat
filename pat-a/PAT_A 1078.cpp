//PAT_A 1078
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int N = 11111;
bool isPrime(int n) {
	if (n <= 1)return false;
	int sqr = (int)sqrt(1.0 * n);
	for (int i = 2; i <= sqr; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
bool HashTable[N] = { false };//HashTable[i]==false，表示i号位没有被使用
int main() {
	int n, Tsize, a;
	(void)scanf("%d %d", &Tsize, &n);
	while (isPrime(Tsize) == false)Tsize++;
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &a);
		int key = a % Tsize;
		if (HashTable[key] == false) {
			HashTable[key] = true;
			printf("%d", key);
		}
		else {
			int step;
			for (step = 1; step < Tsize; step++) {
				key = (a + step * step) % Tsize;
				if (HashTable[key] == false) {
					HashTable[key] = true;
					printf("%d", key);
					break;
				}
			}
			if (step == Tsize)printf("-");
		}
		if (i < n - 1)printf(" ");
	}
	return 0;
}
