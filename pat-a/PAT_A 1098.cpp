//PAT_A 1098
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 111;
int origin[maxn], tempOri[maxn], changed[maxn];
int n;
bool isSame(int A[], int B[]) {
	for (int i = 1; i <= n; i++) {
		if (A[i] != B[i])return false;
	}
	return true;
}
void showArray(int A[]) {
	for (int i = 1; i <= n; i++) {
		printf("%d", A[i]);
		if (i < n)printf(" ");
		else printf("\n");
	}
}
bool insertSort() {//插入排序
	bool flag = false;
	for (int i = 2; i <= n; i++) {
		if (i != 2 && isSame(tempOri, changed))flag = true;//初始序列不参与比较
		sort(tempOri, tempOri + 1 + i);
		if (flag == true)return true;
	}
	return false;
}
void downAdjust(int low, int high) {
	int i = low, j = 2 * i;
	while (j <= high) {
		if (j + 1 <= high && tempOri[j + 1] > tempOri[j])j++;//右孩子大于左孩子
		if (tempOri[j] > tempOri[i]) {
			swap(tempOri[i], tempOri[j]);
			i = j;
			j = 2 * i;
		}
		else break;
	}
}
void heapSort() {
	bool flag = false;
	for (int i = n / 2; i >= 1; i--) {//建堆
		downAdjust(i, n);
	}
	for (int i = n; i > 1; i--) {
		if (i != n && isSame(tempOri, changed))flag = true;
		swap(tempOri[i], tempOri[1]);
		downAdjust(1, i - 1);
		if (flag == true) {
			showArray(tempOri);
			return;                             
		}
	}
}
int main() {
	(void)scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		(void)scanf("%d", &origin[i]);
		tempOri[i] = origin[i];
	}
	for (int i = 1; i <= n; i++) {
		(void)scanf("%d", &changed[i]);
	}
	if (insertSort()) {
		printf("Insertion Sort\n");
		showArray(tempOri);
	}
	else {
		printf("Heap Sort\n");
		for (int i = 1; i <= n; i++) {
			tempOri[i] = origin[i];
		}
		heapSort();
	}
	return 0;
}