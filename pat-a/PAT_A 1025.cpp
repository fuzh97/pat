//PAT_A 1025 PAT Ranking
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Student {
	char id[15];
	int score;
	int location_number;//考场号
	int local_rank;//考场内排名
}stu[30010];
bool cmp(Student a, Student b) {
	if (a.score != b.score)return a.score > b.score;
	else return strcmp(a.id, b.id) < 0;
}
int main() {
	int n, k, num = 0;//num为考生总人数
	(void)scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		(void)scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			(void)scanf("%s %d", stu[num].id, &stu[num].score);
			stu[num].location_number = i;
			num++;
		}
		sort(stu + num - k, stu + num, cmp);//对考场内进行排序
		stu[num - k].local_rank = 1;//计算考场内的排名。
		for (int j = num - k + 1; j < num; j++) {
			if (stu[j].score == stu[j - 1].score)stu[j].local_rank = stu[j - 1].local_rank;
			else stu[j].local_rank = j + 1 - (num - k);
		}
	}
	printf("%d\n", num);
	sort(stu, stu + num, cmp);//对所有考生进行排序
	int rank = 1;
	for (int i = 0; i < num; i++) {
		if (i > 0 && stu[i].score != stu[i - 1].score)rank = i + 1;
		printf("%s %d %d %d\n", stu[i].id, rank, stu[i].location_number, stu[i].local_rank);
	}
	return 0;
}