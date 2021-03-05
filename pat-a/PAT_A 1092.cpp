//PAT_A 1092
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1010;
int HashTable[80] = { 0 };
int change(char c) {//将字符c转换为数字
	if (c >= '0' && c <= '9')return c - '0';
	else if (c >= 'A' && c <= 'Z')return c - 'A' + 10;
	else if (c >= 'a' && c <= 'z')return c - 'a' + 36;
}
int main() {
	char str1[maxn] = { '\0' }, str2[maxn] = { '\0' };
	int miss = 0, len1, len2;
	(void)scanf("%s", str1);
	(void)getchar();
	(void)scanf("%s", str2);
	len1 = strlen(str1);
	len2 = strlen(str2);
	for (int i = 0; i < len1; i++) {//处理str1
		int temp = change(str1[i]);
		HashTable[temp]++;
	}
	bool flag = true;//标志是否能输出
	for (int i = 0; i < len2; i++) {//处理str2
		int temp = change(str2[i]);
		HashTable[temp]--;
		if (HashTable[temp] < 0) {
			miss++;
			flag = false;
		}
	}
	if (flag == false)printf("No %d\n", miss);
	else printf("Yes %d\n", len1 - len2);
	return 0;
}