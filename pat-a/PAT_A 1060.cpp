//PAT_A 1060
#include<iostream>
#include<string>
using namespace std;
int n;
string deal(string s, int& e) {
	int k = 0;
	while (s.length() > 0 && s[0] == '0') {//去除前导0
		s.erase(s.begin());
	}
	if (s[0] == '.') {//s<1 0.a1a2..
		s.erase(s.begin());
		while (s.length() > 0 && s[0] == '0') {
			s.erase(s.begin());
			e--;
		}
	}
	else {//s>1 找见后面的小数点删除
		while (k < s.length() && s[k] != '.') {//寻找小数点的位置，同时记录指数
			k++;
			e++;
		}
		if (k < s.length())s.erase(s.begin() + k);//说明存在小数点，删掉小数点
	}
	if (s.length() == 0)e = 0;//去除前导0之后为0，说明这个数是0
	int num = 0;
	k = 0;
	string res;
	while (num < n) {//还没有到达精度。
		if (k < s.length()) {
			res += s[k];
			k++;
		}
		else res += '0';
		num++;
	}
	return res;
}
int main() {
	string s1, s2, s3, s4;
	cin >> n >> s1 >> s2;
	int e1 = 0, e2 = 0;
	s3 = deal(s1, e1);
	s4 = deal(s2, e2);
	if (s3 == s4 && e1 == e2) {
		cout << "YES 0." << s3 << "*10^" << e1 << endl;
	}
	else cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;
	return 0;
}