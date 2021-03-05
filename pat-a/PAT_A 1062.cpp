//PAT_A 1062 Talent and Virtue
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Students {
	char id[10];
	int moral, talent, sum;//德分，才分，总分
	int flag;//表示第几类考生
}stu[100010];
bool cmp(Students a, Students b) {
	if (a.flag != b.flag)return a.flag < b.flag;//类别从小到大排序
	else if (a.sum != b.sum)return a.sum > b.sum;//同一类别，总分高的在前
	else if (a.moral != b.moral)return a.moral > b.moral;//总分相同，德分高的在前
	else return strcmp(a.id, b.id) < 0;//德分相同，准考证号小的在前
}
int main() {
	int n, L, H, m = 0;//m表示不及格人数
	(void)scanf("%d %d %d", &n, &L, &H);
	for (int i = 0; i < n; i++) {
		(void)scanf("%s %d %d", stu[i].id, &stu[i].moral, &stu[i].talent);
		stu[i].sum = stu[i].moral + stu[i].talent;
		if (stu[i].moral < L || stu[i].talent < L) {
			stu[i].flag = 5;
			m++;
		}
		else if (stu[i].moral >= H && stu[i].talent >= H)stu[i].flag = 1;
		else if (stu[i].moral >= H && stu[i].talent < H)stu[i].flag = 2;
		else if (stu[i].moral >= stu[i].talent)stu[i].flag = 3;
		else stu[i].flag = 4;
	}
	sort(stu, stu + n, cmp);
	printf("%d\n", n - m);//及格人数
	for (int i = 0; i < n - m; i++) {
		printf("%s %d %d\n", stu[i].id, stu[i].moral, stu[i].talent);
	}
	return 0;
}
