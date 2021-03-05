//PAT_A 1026
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int k = 111;
const int inf = 0x3fffffff;
struct Player{
	int arriveTime, startTime, trainTime;//到达时间，训练开始时间，训练时长
	bool isVip;//是否Vip
}newPlayer;
struct Table {
	int endTime, numSever;//结束时间 服务人数
	bool isVip;//是否时Vip球员
}table[k];
vector<Player> player;
int convertTime(int h, int m, int s) {
	return h * 3600 + m * 60 + s;
}
bool cmpArriveTime(Player a, Player b) {//按照先来后到排序
	return a.arriveTime < b.arriveTime;
}
bool cmpStartTime(Player a, Player b) {//按到达时间排序
	return a.startTime < b.startTime;
}
int nextVipPlayer(int VIPi) {
	VIPi++;
	while (VIPi < player.size() && player[VIPi].isVip == 0)VIPi++;
	return VIPi;
}
void allotTable(int pId, int tId) {//将编号为tId的桌子分配给pId的选手
	if (player[pId].arriveTime <= table[tId].endTime) {
		player[pId].startTime = table[tId].endTime;
	}
	else player[pId].startTime = player[pId].arriveTime;
	table[tId].endTime = player[pId].startTime + player[pId].trainTime;
	table[tId].numSever++;
}
int main() {
	int n, k, m, VIPtable;
	(void)scanf("%d", &n);
	int stTime = convertTime(8, 0, 0);
	int edTime = convertTime(21, 0, 0);
	for (int i = 0; i < n; i++) {
		int hh, mm, ss, trainTime, isVip;
		(void)scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &trainTime, &isVip);
		newPlayer.arriveTime = convertTime(hh, mm, ss);
		newPlayer.startTime = edTime;//初始化
		if (newPlayer.arriveTime >= edTime)continue;
		if (trainTime >= 120)newPlayer.trainTime = 7200;
		else newPlayer.trainTime = trainTime * 60;
		newPlayer.isVip = isVip;
		player.push_back(newPlayer);
	}
	(void)scanf("%d %d", &k, &m);
	for (int i = 1; i <= k; i++) {
		table[i].endTime = stTime;
		table[i].numSever = table[i].isVip = 0;//初始化
	}
	for (int i = 0; i < m; i++) {
		(void)scanf("%d", &VIPtable);
		table[VIPtable].isVip = 1;
	}
	sort(player.begin(), player.end(), cmpArriveTime);
	int i = 0, vipi = -1;
	vipi = nextVipPlayer(vipi);
	while (i < player.size()) {
		int idx = -1, minEndTime = inf;
		for (int j = 1; j <= k; j++) {
			if (table[j].endTime < minEndTime) {
				minEndTime = table[j].endTime;
				idx = j;
			}
		}
		if (table[idx].endTime >= edTime)break;//关门
		if (player[i].isVip == 1 && i < vipi) {//说明当前i号球员时vip球员且已经在训练
			i++;
			continue;
		}
		if (table[idx].isVip == 1) {
			if (player[i].isVip == 1) {
				//3-1 如果最早空闲的球桌idx是VIP球桌，且队首球员是VIP球员，那么把球桌idx分配给他
				allotTable(i, idx);
				if (vipi == i)vipi = nextVipPlayer(vipi);
				i++;
			}
			else {
				//3-2 如果最早空闲的球桌idx是VIP球桌，且队首球员不是VIP球员，那么查看第一个VIP球员是否可以在球桌idx空闲之前到达，如果是，把球桌idx分配给VIP球员（让其插队），否则，还是把球桌分配给队首球员。
				if (vipi < player.size() && player[vipi].arriveTime <= table[idx].endTime) {//注意这里没有i++
					allotTable(vipi, idx);
					vipi = nextVipPlayer(vipi);
				}
				else {
					allotTable(i, idx);
					i++;
				}
			}
		}
		else {
			if (player[i].isVip == 0) {
				//3-3 如果最早空闲的球桌idx不是VIP球桌，且队首球员不是VIP球员，那么把球桌idx分配给他。
				allotTable(i, idx);
				i++;
			}
			else {
				//3-4 如果最早空闲的球桌idx不是VIP球桌，且队首球员是VIP球员，那么查询最早空闲的VIP球桌VIPidx，看其是否在该VIP球员到达之前空闲，如果是，就把球桌VIPidx分配给该球员。
				int VipIdx = -1, minVipEndTime = inf;
				for (int j = 1; j <= k; j++) {
					if (table[j].isVip == 1 && table[j].endTime < minVipEndTime) {
						minEndTime = table[j].endTime;
						VipIdx = j;
					}
				}
				if (VipIdx != -1 && player[i].arriveTime >= table[VipIdx].endTime) {
					//vip球桌存在，空闲时间比队员来得早 相当于这个桌子被预约了
					allotTable(i, VipIdx);
					if (vipi == i)vipi = nextVipPlayer(vipi);
					i++;
				}
				else {
					//VIP球员到，VIP球桌还没有空闲，或VIP球桌不存在
					allotTable(i, idx);
					if (vipi == i)vipi = nextVipPlayer(vipi);
					i++;

				}
			}
		}
	}
	sort(player.begin(), player.end(), cmpStartTime);//按开始训练时间排序输出
	for (i = 0; i < player.size() && player[i].startTime < edTime; i++) {
		int t1 = player[i].arriveTime;
		int t2 = player[i].startTime;
		printf("%02d:%02d:%02d ", t1 / 3600, t1 % 3600 / 60, t1 % 60);
		printf("%02d:%02d:%02d ", t2 / 3600, t2 % 3600 / 60, t2 % 60);
		printf("%.0f\n", round((t2 - t1) / 60.0));
	}
	for (int i = 1; i <= k; i++) {
		printf("%d", table[i].numSever);
		if (i < k)printf(" ");
	}
	return 0;
}