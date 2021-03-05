//PAT_A 1100
#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;
string unitDigit[13] = { "tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" };
string tenDigit[13] = { "tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou" };
string NumToStr[170];
map<string, int>strToNum;
void init() {//打表
	for (int i = 0; i < 13; i++) {
		NumToStr[i] = unitDigit[i];//个位为0-12 十位为0
		strToNum[unitDigit[i]] = i;
		NumToStr[i * 13] = tenDigit[i];//十位为0，12，个位为0
		strToNum[tenDigit[i]] = i * 13;
	}
	for (int i = 1; i < 13; i++) {//剩余
		for (int j = 1; j < 13; j++) {
			string str = tenDigit[i] + " " + unitDigit[j];
			NumToStr[i * 13 + j] = str;
			strToNum[str] = i * 13 + j;
		}
	}
}
int main() {
	init();
	int T;
	(void)scanf("%d", &T);
	(void)getchar();
	for (int i = 0; i < T; i++) {
		string str;
		getline(cin, str);
		if (str[0] >= '0' && str[0] <= '9') {//数字
			int num = 0;
			for (int i = 0; i < str.length(); i++) {
				num = num * 10 + (str[i] - '0');
			}
			cout << NumToStr[num] << endl;
		}
		else cout << strToNum[str] << endl;
	}
	return 0;
}