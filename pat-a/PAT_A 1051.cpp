//PAT_A 1051
#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
int main() {
	int m, n, k;//栈的最大容量，数字个数，查询次数
	(void)scanf("%d %d %d", &m, &n, &k);
	vector<int> arr(n + 1);//保存输入的序列
	stack<int> st;
	while (k--) {
		while (!st.empty())st.pop();//清空栈
		for (int i = 1; i <= n; i++) {
			(void)scanf("%d", &arr[i]);
		}
		int current = 1;//当前到第几个元素
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			st.push(i);
			if (st.size() > m) {
				flag = false;
				break;
			}
			while (!st.empty() && st.top() == arr[current]) {
				st.pop();
				current++;
			}
		}
		if (st.empty() && flag == true)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
