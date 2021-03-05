//PAT_A 1082 Read Number in Chinese
#include<cstdio>
#include<cstring>
using namespace std;
char num[10][5] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
char wei[5][5] = { "Shi","Bai","Qian","Wan","Yi" };
int main() {
	char str[15];
	(void)scanf("%s", str);
	int len = strlen(str);
	int left = 0, right = len - 1;//right与left分别指向字符串首尾元素，left指向要输出的位，right指向与left同节的个位
	if (str[0] == '-') {//如果为负数，则输出“Fu”，并把left右移一位
		printf("Fu");
		left++;
	}
	while (left + 4 <= right) {
		right -= 4;//right每次左移四位，直到left与right在同一节
	}
	while (left < len) {//每次循环处理数字的一节
		bool flag = false;//flag==false表示没有积累的0
		bool isPrint = false;//isPrint==flase表示该节没有输出过其中的位
		while (left <= right) {//从左至右处理数字中某节的每一位
			if (left > 0 && str[left] == '0') {//如果当前位为0且不是首位令flag=true
				flag = true;
			}
			else {//如果当前位不为0，则判断是否有累积的0
				if (flag == true) {
					printf(" ling");
					flag = false;
				}
				if (left > 0)printf(" ");//只要不是首位，每一位之前都要输出空格
				printf("%s", num[str[left] - '0']);
				isPrint = true;//isPrint==true表示本节存在输出过的数字，则需要在节之后输出单位
				if (left != right) {//如果left==right表示此时该输出各位，不需要输出单位，跳过
					printf(" %s", wei[right - left - 1]);
				}
			}
			left++;//left右移一位
		}
		if (isPrint == true && right != len - 1) {//当len-1==right时表示此时处理的为个节，不需要输出
			printf(" %s", wei[(len - 1 - right) / 4 + 2] );
		}
		right += 4;
	}
	return 0;
}