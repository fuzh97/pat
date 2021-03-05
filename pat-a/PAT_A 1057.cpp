//PAT_A 1057
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int maxn = 100010;
const int sqrN = 316;//分块个数
stack<int> st;
int block[sqrN], table[maxn];
void PeekMedian(int k) {
	int sum = 0, index = 0;//当前累计存在的个数，块号
	while (sum + block[index] < k) {
		sum += block[index];
		index++;
	}
	int num = index * sqrN;
	while (sum + table[num] < k) {
		sum += table[num];
		num++;
	}
	printf("%d\n", num);
	return;
}
void push(int x) {
	st.push(x);
	block[x / sqrN]++;
	table[x]++;
}
void pop() {
	int x = st.top();
	st.pop();
	block[x / sqrN]--;
	table[x]--;
	printf("%d\n", x);
}
int main() {
	int x, query;
	char cmd[20];
	fill(block, block + sqrN, 0);
	fill(table, table + maxn, 0);
	(void)scanf("%d", &query);
	for (int i = 0; i < query; i++) {
		(void)scanf("%s", cmd);
		if (strcmp(cmd, "Push") == 0) {
			(void)scanf("%d", &x);
			push(x);
		}
		else if (strcmp(cmd, "Pop") == 0) {
			if (st.empty() == true)printf("Invalid\n");
			else pop();
		}
		else {
			if (st.empty() == true)printf("Invalid\n");
			else {
				int k = st.size();
				if (k % 2 == 1)k = k / 2 + 1;
				else k /= 2;
				PeekMedian(k);
			}
		}
	}
	return 0;
}