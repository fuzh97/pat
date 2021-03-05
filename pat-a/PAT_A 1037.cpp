//PAT_A 1037
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int a[maxn], b[maxn];
bool cmp(int a, int b) {
    return a < b;
}
int main() {
    int n, m;
    (void)scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        (void)scanf("%d", &a[i]);
    }
    (void)scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        (void)scanf("%d", &b[i]);
    }
    sort(a, a + n, cmp);
    sort(b, b + n, cmp);
    int i = 0, j, ans = 0;//ans存放乘积
    while (i < n && i < m && a[i] < 0 && b[i] < 0) {//负数
        ans += a[i] * b[i];
        i++;
    }
    i = n - 1;
    j = m - 1;
    while (j >= 0 && i >= 0 && a[i] > 0 && b[j] > 0) {
        ans += a[i] * b[j];
        i--;
        j--;
    }
    printf("%d", ans);
    return 0;
}