//PAT_A 1017
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int inf = 0x3fffffff;
const int k = 111;
struct Customer{
	int comeTime, serveTime;
};
vector<Customer> custom;
int convertTime(int h, int m, int s) {
	return h * 3600 + m * 60 + s;
}
bool cmp(Customer a, Customer b) {//按先来后到的顺序排序
	return a.comeTime < b.comeTime;
}
int main() {
	int c, w, totalTime = 0, endTime[k];//客户数 窗口数 总服务时间 每一个窗口当前服务客户的结束时间
	int stTime = convertTime(8, 0, 0), edTime = convertTime(17, 0, 0);
	(void)scanf("%d %d", &c, &w);
	for (int i = 0; i < w; i++) {
		endTime[i] = stTime;//窗口开始服务时间初始化为8：00
	}
	for (int i = 0; i < c; i++) {
		int hh, mm, ss, severTime;
		(void)scanf("%d:%d:%d %d", &hh, &mm, &ss, &severTime);
		int comeTime = convertTime(hh, mm, ss);
		if (comeTime > edTime)continue;
		Customer newCustomer;
		newCustomer.comeTime = comeTime;
		if (severTime >= 60)newCustomer.serveTime = 3600;
		else newCustomer.serveTime = severTime * 60;
		custom.push_back(newCustomer);
	}
	sort(custom.begin(), custom.end(), cmp);
	for (int i = 0; i < custom.size(); i++) {
		int index = -1, minEndTime = inf;
		for (int j = 0; j < w; j++) {//最早结束服务的窗口
			if (endTime[j] < minEndTime) {
				minEndTime = endTime[j];
				index = j;
			}
		}
		if (endTime[index] <= custom[i].comeTime) {//顾客在窗口空闲之后才来
			endTime[index] = custom[i].comeTime + custom[i].serveTime;
		}
		else {
			totalTime += endTime[index] - custom[i].comeTime;
			endTime[index] += custom[i].serveTime;
		}
	}
	if (custom.size() == 0)printf("0.0");
	else printf("%.1f", totalTime / 60.0 / custom.size());
	return 0;
}