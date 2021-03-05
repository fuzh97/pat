//PAT_A 1103
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n, k, p, maxFacSum = -1;//最大底数之和
vector<int> fac, ans, temp;
int power(int x) {
	int ans = 1;
	for (int i = 0; i < p; i++) {
		ans *= x;
	}
	return ans;
}
void init() {//预处理，i^p没有超过n，把i^p加入fac
	int i = 0, temp = 0;
	while (temp <= n) {
		fac.push_back(temp);
		temp = power(++i);
	}
}
void dfs(int index, int nowK, int sum, int facSum) {
	if (sum == n && nowK == k) {
		if (facSum > maxFacSum) {
			ans = temp;
			maxFacSum = facSum;//更新最大底数之和
		}
	}
	if (sum > n || nowK > k)return;
	if (index - 1 >= 0) {
		temp.push_back(index);//继续选index
		dfs(index, nowK + 1, sum + fac[index], facSum + index);
		temp.pop_back();//去掉刚刚加进去的数，再进入不选的分支
		dfs(index - 1, nowK, sum, facSum);//不选index
	}
}
int main() {
	(void)scanf("%d %d %d", &n, &k, &p);
	init();
	dfs(fac.size() - 1, 0, 0, 0);
	if (maxFacSum == -1)printf("Impossible\n");
	else {
		printf("%d = %d^%d", n, ans[0], p);
		for (int i = 1; i < ans.size(); i++) {
			printf(" + %d^%d", ans[i], p);
		}
	}
	return 0;
}