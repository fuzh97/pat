//PAT_A 1073
#include<cstdio>
#include<cstring>
using namespace std;
int main() {
	char str[10010];
	(void)scanf("%s", &str);
	int len = strlen(str);
	if (str[0] == '-')printf("-");
	int pos = 0;//存放E的位置
	while (str[pos] != 'E') {//定位E的位置
		pos++;
	}
	int exp = 0;
	for (int i = pos + 2; i < len; i++) {
		exp = exp * 10 + (str[i] - '0');
	}//计算指数
	if (exp == 0) {//指数为0 将exp前的照原样输出
		for (int i = 1; i < pos; i++) {
			printf("%c", str[i]);
		}
	}
	if (str[pos + 1] == '-') {//指数为负，输出0.0000xxx，其中0的个数等于exp-2
		printf("0.");
		for (int i = 0; i < exp - 1; i++) {
			printf("0");
		}
		printf("%c", str[1]);
		for (int i = 3; i < pos; i++) {//跳过小数点
			printf("%c", str[i]);
		}
	}
	else {//指数为正
		for (int i = 1; i < pos; i++) {//输出小数点移动之后的数
			if (str[i] == '.')continue;
			printf("%c", str[i]);
			if (i == exp + 2 && pos - 3 != exp) {
				//pos-3是从小数点到exp之间所有的数字，如果这些数字的小数点位数等于exp，
				//则说明小数点移至最后一位，这种情况不需要输出小数点
				printf(".");
			}
		}
		for (int i = 0; i < exp - (pos - 3); i++) {
			printf("0");
		}
	}
	return 0;
}