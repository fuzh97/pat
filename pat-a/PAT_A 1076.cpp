//PAT_A 1076
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1010;
struct Node {
	int id;
	int layer;
};
vector<Node> Adj[maxn];//邻接表
bool inq[maxn] = { false };
int bfs(int s, int L) {
	int numForward = 0;//转发数
	queue<Node> q;
	Node start{ s,0 };
	q.push(start);
	inq[start.id] = true;
	while (!q.empty()) {
		Node topNode = q.front();
		q.pop();
		int u = topNode.id;
		for (int i = 0; i < Adj[u].size(); i++) {
			Node next = Adj[u][i];
			next.layer = topNode.layer + 1;
			if (inq[next.id] == false && next.layer <= L){
				q.push(next);
				inq[next.id] = true;
				numForward++;
			}
		}
	}
	return numForward;
}
int main() {
	Node user;
	int n, L, numFollow, idFollow;
	(void)scanf("%d %d", &n, &L);
	for (int i = 1; i <= n; i++) {
		user.id = i;
		(void)scanf("%d", &numFollow);
		for (int k = 0; k < numFollow; k++) {//建立idFollow->user的边
			(void)scanf("%d", &idFollow);
			Adj[idFollow].push_back(user);
		}
	}
	int numQuery, s;
	(void)scanf("%d", &numQuery);
	for (int i = 0; i < numQuery; i++) {
		fill(inq, inq + maxn, false);
		(void)scanf("%d", &s);
		int numForward = bfs(s, L);
		printf("%d\n", numForward);
	}
	return 0;
}