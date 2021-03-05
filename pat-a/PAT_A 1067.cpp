//PAT_A 1067
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int pos[maxn];//存放当前各个数字所处的位置编号
int main() {
	int n, ans = 0;
	(void)scanf("%d", &n);
	int count = n - 1, num;//count存放除0以外不在本位上的数的个数
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &num);
		pos[num] = i;
		if (num == i && num != 0)count--;//已经在本位上了，后续不移动
	}
	int k = 1;//存放除0以当前不在本位上的最小的数。
	while (count > 0) {
		if (pos[0] == 0) {//0回到本位，找见一个不在本位上的交换
			while (k < n) {
				if (pos[k] != k) {
					swap(pos[0], pos[k]);
					ans++;//交换次数
					break;
				}
				k++;
			}
		}
		while (pos[0] != 0) {
			swap(pos[0], pos[pos[0]]);
			ans++;//交换次数加一
			count--;//不在本位上的个数减一
		}

	}
	printf("%d", ans);
	return 0;
}
