//PAT_A 1034
#include<iostream>
#include<string>
#include<map>
using namespace std;
const int maxn = 2010;
map<int, string>intToString;
map<string, int>stringToInt;
map<string, int>Gang;
int G[maxn][maxn] = { 0 }, weight[maxn] = { 0 };//邻接矩阵
int n, k, numPreson = 0;
bool vis[maxn] = { false };
void dfs(int nowVisit, int& head, int& numMember, int& totalValue) {
	//当前访问编号，头目，成员编号，总边权
	numMember++;
	vis[nowVisit] = true;
	if (weight[nowVisit] > weight[head]) {
		head = nowVisit;
	}
	for (int i = 0; i < numPreson; i++) {//枚举所有人
		if (G[nowVisit][i] > 0) {
			totalValue += G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0;//防止回头，删掉这条边
			if (vis[i] == false) {
				dfs(i, head, numMember, totalValue);
			}
		}
	}
}
void dfsTrave() {
	for (int i = 0; i < numPreson; i++) {
		if (vis[i] == false) {
			int head = i, numMember = 0, totalValue = 0;
			dfs(i, head, numMember, totalValue);
			if (numMember > 2 && totalValue > k) {
				Gang[intToString[head]] = numMember;
			}
		}
	}
}
int change(string str) {
	if (stringToInt.find(str) != stringToInt.end())return stringToInt[str];
	else {
		stringToInt[str] = numPreson;
		intToString[numPreson] = str;
		return numPreson++;
	}
}
int main() {
	int w;
	string str1, str2;
	cin >> n >> k;//边的个数，阈值
	for (int i = 0; i < n; i++) {
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	dfsTrave();
	cout << Gang.size() << endl;
	for (map<string, int>::iterator it = Gang.begin(); it != Gang.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;

}