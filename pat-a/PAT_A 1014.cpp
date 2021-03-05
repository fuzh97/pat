//PAT_A 1014
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 1111;
int convertTime(int hh, int mm) {
	return hh * 60 + mm;
}
struct Window {
	int endTime, popTime;//最后一个客户结束服务的时间，队首客户结束服务的时间
	queue<int> q;//这个窗口的排队队列
}window[20];
int ans[maxn], need[maxn];//每个客户的结束时间与需要时间
int main() {
	int n, m, k, query, q, inIndex = 0;
	(void)scanf("%d %d %d %d", &n, &m, &k, &query);
	for (int i = 0; i < k; i++) {
		(void)scanf("%d", &need[i]);
	}
	for (int i = 0; i < n; i++) {
		window[i].popTime = window[i].endTime = convertTime(8, 0);//初始时间设在8点
	}
	for (int i = 0; i < min((n * m), k); i++) {
		window[inIndex % n].q.push(inIndex);
		window[inIndex % n].endTime += need[inIndex];
		if (inIndex < n)window[inIndex].popTime += need[inIndex];//窗口第一个客户
		ans[inIndex] = window[inIndex % n].endTime;//答案保存为当前队列结束时间
		inIndex++;
	}
	for (; inIndex < k; inIndex++) {
		int idx = -1, minPopTime = 1 << 30;
		for (int i = 0; i < n; i++) {
			if (window[i].popTime < minPopTime) {
				minPopTime = window[i].popTime;
				idx = i;
			}
		}
		window[idx].q.pop();
		window[idx].q.push(inIndex);
		window[idx].endTime += need[inIndex];
		window[idx].popTime += need[window[idx].q.front()];
		ans[inIndex] += window[idx].endTime;
	}
	for (int i = 0; i < query; i++) {
		(void)scanf("%d", &q);
		if (ans[q - 1] - need[q - 1] >= convertTime(17, 0))printf("Sorry\n");//在17：00之后才能服务
		else printf("%02d:%02d\n", ans[q - 1] / 60, ans[q - 1] % 60);
	}
	return 0;

}
