//PAT_A 1033
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 510;
const int INF = 100000000;
struct station {
	double price, dis;//price表示价格,dis表示到起点的距离
}st[maxn];
bool cmp(station a, station b) {
	return a.dis < b.dis;
}
int main() {
	int n;
	double Cmax, D, Davg;
	//Cmax:油箱最大油量，D：与终点距离，Davg:单位汽油能够支持的前景距离，n：加油站个数
	(void)scanf("%lf %lf %lf %d", &Cmax, &D, &Davg, &n);
	for (int i = 0; i < n; i++) {
		(void)scanf("%lf %lf", &st[i].price, &st[i].dis);
	}
	st[n].price = 0;
	st[n].dis = D;//最后一个加油站
	sort(st, st + n, cmp);//按距离排序
	if (st[0].dis != 0) {//第一个加油站不在起点
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	int now = 0;//当前所处加油站编号
	double ans = 0, nowTank = 0, Max = Cmax * Davg;//总花费，当前邮箱剩余油量，加满油的行驶距离
	while (now < n) {
		int k = -1;//最低油价加油站编号
		double priceMin = INF;
		for (int i = now + 1; i <= n && st[i].dis - st[now].dis <= Max; i++) {
			if (st[i].price < priceMin) {
				priceMin = st[i].price;
				k = i;
				if (priceMin < st[now].price)break;//如果找见比当前加油站便宜的加油站，中断循环
			}
		}
		if (k == -1) break;//满油状态下无法找到加油站，退出循环结果
		//找见可到达的加油站k，计算花费
		double need = (st[k].dis - st[now].dis) / Davg;
		if (priceMin < st[now].price) {//如果加油站k的油价低于当前油价，只买足够到加油站k的油
			if (nowTank < need) {
				ans += (need - nowTank) * st[now].price;
				nowTank = 0;//到达之后
			}
			else {
				nowTank -= need;//直接到达k
			}
		}
		else {//没有加油站的价格低于当前油价，直接加满，到k
			ans += (Cmax - nowTank) * st[now].price;
			nowTank = Cmax - need;//到达之后
		}
		now = k;
	}
	if (now == n) {//到达终点
		printf("%.2f\n", ans);
	}
	else {
		printf("The maximum travel distance = %.2f", st[now].dis + Max);
	}
	return 0;
}