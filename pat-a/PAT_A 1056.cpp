//PAT_A 1056
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 1010;
struct  Mouse {
	int weight;
	int R;
};
int main() {
	int np, ng, order;//np只老鼠，每ng只分为一组
	(void)scanf("%d %d", &np, &ng);
	vector<Mouse> mouse(np);
	for (int i = 0; i < np; i++) {
		(void)scanf("%d", &mouse[i].weight);
	}
	queue <int> q;
	for (int i = 0; i < np; i++) {
		(void)scanf("%d", &order);
		q.push(order);
	}
	int temp = np, group;
	while (q.size() != 1) {
		if (temp % ng == 0)group = temp / ng;//刚好可以分ng个组
		else group = temp / ng + 1;//不能刚好分ng个组
		for (int i = 0; i < group; i++) {
			int k = q.front();
			for (int j = 0; j < ng; j++) {
				if (i * ng + j >= temp)break;//最后一组的情况
				int front = q.front();
				if (mouse[front].weight > mouse[k].weight)k = front;//质量最大的老鼠
				mouse[front].R = group + 1;
				q.pop();
			}
			q.push(k);//胜利的老鼠晋级
		}
		temp = group;//group只老鼠晋级，下轮老鼠总数为group
	}
	mouse[q.front()].R = 1;//最后一只老鼠获胜，排名为1
	for (int i = 0; i < np; i++) {
		printf("%d", mouse[i].R);
		if (i < np - 1)printf(" ");
	}
	return 0;
}