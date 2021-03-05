//PAT_A 1095
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 10010;
struct Car {
	char id[18];//车牌号
	int time;//时间都转化成秒 00:00:00记为0
	char status[4];
}all[maxn], vaild[maxn];
int num = 0;//有效记录的条数
map<string, int>parkTime;
int timeToInt(int hh, int mm, int ss) {
	return hh * 3600 + mm * 60 + ss;
}
bool cmpByIdAndTime(Car a, Car b) {//按车牌号排序，否则按时间大小
	if (strcmp(a.id, b.id) != 0)return strcmp(a.id, b.id) < 0;	
	else return a.time < b.time;
}
bool cmpByTime(Car a, Car b) {//按时间大小排序
	return a.time < b.time;
}
int main() {
	int n, k, hh, mm, ss;
	int maxTime = -1;//最长总停留时间
	(void)scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		(void)scanf("%s %d:%d:%d %s", all[i].id, &hh, &mm, &ss, all[i].status);
		all[i].time = timeToInt(hh, mm, ss);
	}
	sort(all, all + n, cmpByIdAndTime);
	for (int i = 0; i < n - 1; i++) {
		if ((strcmp(all[i].id, all[i + 1].id) == 0) &&//判断有效记录，相邻两个记录是同一车牌，且前一个为'on'，后一个为'out'
			(strcmp(all[i].status, "in") == 0) &&
			(strcmp(all[i + 1].status, "out") == 0)) {
			vaild[num++] = all[i];
			vaild[num++] = all[i + 1];
			int inTime = all[i + 1].time - all[i].time;
			if (parkTime.count(all[i].id) == 0) {//如果map中还没有这个车牌号，置0。
				parkTime[all[i].id] = 0;
			}
			parkTime[all[i].id] += inTime;
			if (parkTime[all[i].id] > maxTime)maxTime = parkTime[all[i].id];//更新最大总停留时间
		}
	}
	sort(vaild, vaild + num, cmpByTime);//有效记录按时间大小排序
	int now = 0, numCar = 0;//now指向不超过当前查询时间的记录，numCar记录当前由多少辆车
	for (int i = 0; i < k; i++) {
		(void)scanf("%d:%d:%d", &hh, &mm, &ss);
		int time = timeToInt(hh, mm, ss);
		while (now < num && vaild[now].time <= time) {
			if (strcmp(vaild[now].status, "in") == 0)numCar++;
			else numCar--;
			now++;//处理下一条记录。
		}
		printf("%d\n", numCar);
	}
	map<string, int>::iterator it;
	for (it = parkTime.begin(); it != parkTime.end(); it++) {
		if (it->second == maxTime) {
			printf("%s ", it->first.c_str());
		}
	}
	printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);//最长时间
	return 0;
}
