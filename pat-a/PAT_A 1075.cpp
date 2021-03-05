//PAT_A 1075
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 10010;
struct Student {
	int id;
	int score[6];
	bool flag;//是否需要输出，只要有提交就输出
	int score_all;//总分
	int solve;//完美解题数
}stu[maxn];
int n, k, m;
int full[6];
bool cmp(Student a, Student b) {
	if (a.score_all != b.score_all)return a.score_all > b.score_all;
	else if (a.solve != b.solve)return a.solve > b.solve;
	else return a.id < b.id;
}
void init() {
	for (int i = 1; i <= n; i++) {
		stu[i].id = i;
		stu[i].score_all = 0;
		stu[i].solve = 0;
		stu[i].flag = false;
		memset(stu[i].score, -1, sizeof(stu[i].score));
	}
}
int main() {
	(void)scanf("%d%d%d", &n, &k, &m);
	init();
	for (int i = 1; i <= k; i++)(void)scanf("%d", &full[i]);//输入每一道题的满分项
	int u_id, p_id, score_obtained;//考生id，题目id，所获分值
	for (int i = 0; i < m; i++) {
		(void)scanf("%d%d%d", &u_id, &p_id, &score_obtained);
		if (score_obtained != -1)stu[u_id].flag = true;//表示有编译通过的
		if (score_obtained == -1 && stu[u_id].score[p_id] == -1)stu[u_id].score[p_id] = 0;//第一次没有编译通过，该题记0分
		if (score_obtained == full[p_id] && stu[u_id].score[p_id] < full[p_id])stu[u_id].solve++;//第一次完美解题
		if (score_obtained > stu[u_id].score[p_id])stu[u_id].score[p_id] = score_obtained;
	}
	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= k; j++) {
			if (stu[i].score[j] != -1)stu[i].score_all += stu[i].score[j];
		}
	}
	sort(stu + 1, stu + 1 + n, cmp);
	int r = 1;
	for (int i = 1; i <= n && stu[i].flag == true; i++) {
		if (i > 1 && stu[i].score_all != stu[i - 1].score_all)r = i;
		printf("%d %05d %d", r, stu[i].id, stu[i].score_all);
		for (int j = 1; j <= k; j++) {
			if (stu[i].score[j] == -1)printf(" -");
			else printf(" %d", stu[i].score[j]);
		}
		printf("\n");
	}
	return 0;
}