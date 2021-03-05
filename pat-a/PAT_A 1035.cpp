//PAT_A 1035
#include<cstdio>
#include<cstring>
using namespace std;
struct node {
	char username[20];
	char password[20];
	bool ischange;//ischange==true表示已经修改
}T[1005];
int main() {
	int n, cnt = 0;
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		(void)scanf("%s %s", T[i].username, T[i].password);
		T[i].ischange = false;
		int len = strlen(T[i].password);
		for (int j = 0; j < len; j++) {
			if (T[i].password[j] == '1') {
				T[i].password[j] = '@';
				T[i].ischange = true;
			}
			else if (T[i].password[j] == '0') {
				T[i].password[j] = '%';
				T[i].ischange = true;
			}
			else if (T[i].password[j] == 'l') {
				T[i].password[j] = 'L';
				T[i].ischange = true;
			}
			else if (T[i].password[j] == 'O') {
				T[i].password[j] = 'o';
				T[i].ischange = true;
			}
		}
		if (T[i].ischange)cnt++;
	}
	if (cnt == 0) {//没有密码需要修改
		if (n == 1)printf("There is 1 account and no account is modified");
		else printf("There are %d accounts and no account is modified", n);
	}
	else {
		printf("%d\n", cnt);
		for (int i = 0; i < n; i++) {
			if (T[i].ischange == true)
				printf("%s %s\n", T[i].username, T[i].password);
		}
	}
	return 0;
}