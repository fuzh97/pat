//PAT_A 1050
#include<cstdio>
#include<cstring>
const int maxn = 10005;
char a[maxn], b[maxn];
bool HashTable[256] = { false };
int main() {
	(void)scanf("%[^\n]", a);
	(void)getchar();
	(void)scanf("%[^\n]", b);
	int lenA = strlen(a);
	int lenB = strlen(b);
	for (int i = 0; i < lenB; i++) {
		HashTable[b[i]] = true;
	}
	for (int i = 0; i < lenA; i++) {
		if (HashTable[a[i]] == false)printf("%c", a[i]);
	}
	return 0;
}