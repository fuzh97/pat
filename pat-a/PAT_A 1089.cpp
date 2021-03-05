//PAT_A 1089
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 111;
int origin[N], tempOri[N], changed[N];//原始数组，原始备份数组，目标数组
int n;//元素个数
bool isSame(int A[], int B[]) {
	for (int i = 0; i < n; i++) {
		if (A[i] != B[i])return false;
	}
	return true;
}
void showArray(int A[]) {
	for (int i = 0; i < n; i++) {
		printf("%d", A[i]);
		if (i < n - 1)printf(" ");
	}
	printf("\n");
}
bool insertSort() {//插入排序
	bool flag = false;//记录是否存在数组中间步骤与changed数组相同
	//先判断再排序，tempOri里保存的就是要输出的数组
	for (int i = 1; i < n; i++) {
		if (i != 1 && isSame(tempOri, changed)) {
			flag = true;//中间步骤与目标相同，且不是初始序列
		}
		//插入部分
		int temp = tempOri[i], j = i;
		while (j > 0 && tempOri[j - 1] > temp) {
			tempOri[j] = tempOri[j - 1];
			j--;
		}
		tempOri[j] = temp;
		if (flag == true)return true;//找见目标数组
	}
	return false;//没有找见目标数组。
}
void mergeSort() {
	bool flag = false;//记录是否存在数组中间步骤与changed数组相同
	for (int step = 2; step / 2 <= n; step *= 2) {
		if (step != 2 && isSame(tempOri, changed))flag = true;//中间步骤与目标相同，不是初始序列
		for (int i = 0; i < n; i += step) {
			sort(tempOri + i, tempOri + min(i + step, n));
		}
		if (flag == true) {
			showArray(tempOri);
			return;
		}
	}
}
int main() {
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &origin[i]);//原始数组
		tempOri[i] = origin[i];
	}
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &changed[i]);//目标数组
	}
	if (insertSort()) {//插入排序
		printf("Insertion Sort\n");
		showArray(tempOri);
	}
	else {//归并排序
		printf("Merge Sort\n");
		for (int i = 0; i < n; i++) {//复原
			tempOri[i] = origin[i];
		}
		mergeSort();
	}
	return 0;
}