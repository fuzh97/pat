//PAT_A 1080
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Student {
	int GE, GI, sum;
	int r, stuID;
	int cho[6];//志愿编号
}stu[40010];
struct School {
	int quota;//招生人数总额度
	int stuNum;//实际招生人数
	int id[40010];//招收的学生编号d
	int lastAdmit;//最后一个招收的学生编号
}sch[110];
bool cmpStu(Student a, Student b) {
	if (a.sum != b.sum)return a.sum > b.sum;
	else return a.GE > b.GE;
}
bool cmpID(int a, int b) {
	return stu[a].stuID < stu[b].stuID;//考生编号从小到大
}
int main() {
	int n, m, k;
	(void)scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		(void)scanf("%d", &sch[i].quota);
		sch[i].stuNum = 0;
		sch[i].lastAdmit = -1;
	}
	for (int i = 0; i < n; i++) {
		stu[i].stuID = i;
		(void)scanf("%d %d", &stu[i].GE, &stu[i].GI);
		stu[i].sum = stu[i].GE + stu[i].GI;
		for (int j = 0; j < k; j++) {
			(void)scanf("%d", &stu[i].cho[j]);
		}
	}
	sort(stu, stu + n, cmpStu);
	for (int i = 0; i < n; i++) {
		if (i > 0 && stu[i].sum == stu[i - 1].sum && stu[i].GE == stu[i - 1].GE)stu[i].r = stu[i - 1].r;
		else stu[i].r = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int choice = stu[i].cho[j];
			int num = sch[choice].stuNum;
			int last = sch[choice].lastAdmit;
			if (num < sch[choice].quota || last != -1 && stu[i].r == stu[last].r) {//两种录取的办法
				sch[choice].id[num] = i;
				sch[choice].lastAdmit = i;
				sch[choice].stuNum++;
				break;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (sch[i].stuNum > 0) {
			sort(sch[i].id, sch[i].id + sch[i].stuNum, cmpID);
			for (int j = 0; j < sch[i].stuNum; j++) {
				printf("%d", stu[sch[i].id[j]].stuID);
				if (j < sch[i].stuNum - 1)printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}

