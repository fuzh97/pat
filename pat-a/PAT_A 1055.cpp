//PAT_A 1055
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int Age[maxn] = { 0 };//某个年龄的人数
struct  Person {
	int age, worths;
	char name[10];
}ps[maxn], valid[maxn];
bool cmp(Person a, Person b) {
	if (a.worths != b.worths)return a.worths > b.worths;
	else if (a.age != b.age)return a.age < b.age;
	else {
		int s = strcmp(a.name, b.name);
		if (s != 0)return s < 0;
	}
}
int main() {
	int n, k;
	(void)scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		(void)scanf("%s%d%d", ps[i].name, &ps[i].age, &ps[i].worths);
	}
	sort(ps, ps + n, cmp);
	int vaildName = 0;
	for (int i = 0; i < n; i++) {
		if (Age[ps[i].age] < 100) {
			Age[ps[i].age]++;
			valid[vaildName++] = ps[i];//ps[i]加入到新数组中
		}
	}
	int m, ageL, ageR;
	for (int i = 1; i <= k; i++) {
		(void)scanf("%d%d%d", &m, &ageL, &ageR);
		printf("Case #%d:\n", i);
		int printNum = 0;
		for (int j = 0; j < vaildName && printNum < m; j++) {
			if (valid[j].age >= ageL && valid[j].age <= ageR) {
				printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].worths);
				printNum++;
			}
		}
		if (printNum == 0) {
			printf("None\n");
		}
	}
	return 0;
}