	//PAT_A 1036
	#include<cstdio>
	using namespace std;
	struct person {
		char name[15];
		char id[15];
		char gender;
		int gread;
	}M_lowest, F_highest, temp;
	void init() {
		M_lowest.gread = 101;
		F_highest.gread = -1;
	}
	int main() {
		init();
		int n;
		(void)scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			(void)scanf("%s %c %s %d", temp.name, &temp.gender, temp.id, &temp.gread);
			if (temp.gender == 'F' && temp.gread > F_highest.gread)F_highest = temp;
			else if (temp.gender == 'M' && temp.gread < M_lowest.gread)M_lowest = temp;
		}
		if (F_highest.gread == -1)printf("Absent\n");
		else printf("%s %s\n", F_highest.name, F_highest.id);
		if (M_lowest.gread == 101)printf("Absent\n");
		else printf("%s %s\n", M_lowest.name, M_lowest.id);
		if (F_highest.gread == -1 || M_lowest.gread == 101)printf("NA");
		else printf("%d", F_highest.gread - M_lowest.gread);
		return 0;
	}