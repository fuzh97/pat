//PAT_A 1010
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL MAP[256];
LL inf = (1LL << 63) - 1;//long long上界 2^63-1
void init() {
	for (char c = '0'; c <= '9'; c++)MAP[c] = c - '0';
	for (char c = 'a'; c <= 'z'; c++)MAP[c] = c - 'a' + 10;
}
LL convertNum10(char a[], LL radix, LL t) {//将a转换为10进制
	LL ans = 0;
	int len = strlen(a);
	for (int i = 0; i < len; i++) {
		ans = ans * radix + MAP[a[i]];//进制转换
		if (ans<0 || ans>t)return -1;//溢出或ans超过上界t
	}
	return ans;
}
int cmp(char N2[], LL radix, LL t) {//N2的十进制与t比较
	int len = strlen(N2);
	LL ans = convertNum10(N2, radix, t);//ans为N2从radix转换到10进制的值
	if (ans < 0)return 1;//溢出 或N2>t;向左子区间
	if (t > ans)return -1;//t较大，返回-1，
	else if (t == ans)return 0;//相等，返回0
}
LL binarySearch(char N2[], LL left, LL right, LL x) {//二分查找N2的进制
	//判断n2十进制之后与x(N1的十进制)比较
	LL mid;
	while (left <= right) {
		mid = (left + right) / 2;
		int flag = cmp(N2, mid, x);//N2从mid进制转换为10进制后与N1比较
		if (flag == 0)return mid;
		else if (flag == -1)left = mid + 1;//num较小，向右子区间寻找
		else right = mid - 1;//num溢出或num>t，向左子区间寻找
	}
	return -1;//解不存在
}
int findLargestDigit(char N2[]) {//求最大数位（进制）
	int ans = -1, len = strlen(N2);
	for (int i = 0; i < len; i++) {
		if (MAP[N2[i]] > ans) {
			ans = MAP[N2[i]];
		}
	}
	return ans + 1;//进制下界为最大的数加一，如最大的数为9，则进制最小为10进制
}
char N1[20], N2[20], temp[20];
int tag, radix;
int main() {
	init();
	(void)scanf("%s %s %d %d", N1, N2, &tag, &radix);
	if (tag == 2) {//如果radix进制的数为N2，则交换
		strcpy(temp, N1);
		strcpy(N1, N2);
		strcpy(N2, temp);
	}
	LL x = convertNum10(N1, radix, inf);//将N1从radix进制转换为10进制
	LL low = findLargestDigit(N2);//二分下界：N2中最大的数位+1
	LL high = x + 1;//二分上界：下界与N1的十进制数的较大值+1，最大x进制
	LL ans = binarySearch(N2, low, high, x);//在N2的进制中查找转换成10进制之后与N1相等的数
	if (ans == -1)printf("Impossible\n");
	else printf("%lld\n", ans);
	return 0;
}