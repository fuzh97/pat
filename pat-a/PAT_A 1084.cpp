//PAT_A 1084
#include<cstdio>
#include<cstring>
using namespace std;
int main() {
	char str1[100], str2[100];
	bool HashTable[128] = { false };
	(void)scanf("%s", str1);
	(void)scanf("%s", str2);
	int len1 = strlen(str1), len2 = strlen(str2);
	for (int i = 0; i < len1; i++) {
		int j;
		char c1, c2;
		for (j = 0; j < len2; j++) {
			c1 = str1[i];
			c2 = str2[j];
			if (c1 >= 'a' && c1 <= 'z')c1 -= 32;
			if (c2 >= 'a' && c2 <= 'z')c2 -= 32;
			if (c1 == c2)break;
		}
		if (j == len2 && HashTable[c1] == false) {//第二个字符串中没有出现c1并且c1没有输出过
			printf("%c", c1);
			HashTable[c1] = true;
		}
	}
}