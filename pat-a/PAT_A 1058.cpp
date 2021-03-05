//PAT_A 1058
#include<cstdio>
using namespace std;
const int Knut = 1;
const int Sickle = 29 * Knut;
const int Galleon = 17 * Sickle;
int main() {
	long long a1, b1, c1, a2, b2, c2, temp1, temp2, change;
	(void)scanf("%lld.%lld.%lld %lld.%lld.%lld", &a1, &b1, &c1, &a2, &b2, &c2);
	temp1 = a1 * Galleon + b1 * Sickle + c1 * Knut;
	temp2 = a2 * Galleon + b2 * Sickle + c2 * Knut;
	change = temp1 + temp2;
	printf("%lld.%lld.%lld", change / Galleon, (change % Galleon) / Sickle, change % Sickle);
	return 0;
}