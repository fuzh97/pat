//PAT_A 1006
#include<cstdio>
using namespace std;
struct pNode {
	char id[20];
	int hh, mm, ss;
}temp, last, soon;//last存放最晚时间，soon存放最早时间
void init() {
	soon.hh = 24;
	soon.mm = soon.ss = 60;
	last.hh = last.mm = last.ss = 0;
}
bool great(pNode a, pNode b) {//a的时间大于b的时间返回true
	if (a.hh != b.hh)return a.hh > b.hh;
	else if (a.mm != b.mm)return a.mm > b.mm;
	else return a.ss > b.ss;
}
int main() {
	int n;
	init();
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		(void)scanf("%s %d:%d:%d", temp.id, &temp.hh, &temp.mm, &temp.ss);
		if (great(soon, temp))soon= temp;//最早签到时间比最小的时间小
		(void)scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);
		if (great(temp, last))last = temp;//最大签到时间比最大的时间大
	}
	printf("%s %s", soon.id, last.id);
	return 0;
}