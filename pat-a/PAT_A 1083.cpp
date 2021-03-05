//PAT_A 1083
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 50;
struct Student {
	char name[11];
	char id[11];
	int grade;
}stu[maxn];
bool cmp(Student a, Student b) {
	return a.grade > b.grade;
}
int main() {
	int n, lowest, highest;
	bool flag = false;
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		(void)scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
	}
	sort(stu, stu + n, cmp);
	(void)scanf("%d %d", &lowest, &highest);
	for (int i = 0; i < n; i++) {
		if (stu[i].grade >= lowest && stu[i].grade <= highest) {
			flag = true;
			printf("%s %s\n", stu[i].name, stu[i].id);
		}
	}
	if (flag == false)printf("NONE\n");
	return 0;
}