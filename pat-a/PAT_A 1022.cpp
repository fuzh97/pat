//PAT_A 1022
#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<map>
using namespace std;
map<string, set<int> >mpTitle, mpAuthor, mpKey, mpPub, mpYear;
void query(map<string, set<int>>& mp, string& str) {
	if (mp.find(str) == mp.end())printf("Not Found\n");
	else {
		for (set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++) {
			printf("%07d\n", *it);
		}
	}
}
int main() {
	int n, m, id, type;
	string title, author, key, pub, year;
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		(void)scanf("%d", &id);
		char c = getchar();
		getline(cin, title);
		mpTitle[title].insert(id);
		getline(cin, author);
		mpAuthor[author].insert(id);
		while (cin >> key) {
			mpKey[key].insert(id);
			c = getchar();
			if (c == '\n')break;
		}
		getline(cin, pub);
		mpPub[pub].insert(id);
		getline(cin, year);
		mpYear[pub].insert(id);
	}
	string temp;
	(void)scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		(void)scanf("%d: ", &type);
		getline(cin, temp);
		cout << type << ": " << temp << endl;
		//printf("%d: %s\n", type, temp.c_str());
		if (type == 1)query(mpTitle, temp);
		else if (type == 2)query(mpAuthor, temp);
		else if (type == 3)query(mpKey, temp);
		else if (type == 4)query(mpPub, temp);
		else if (type == 5)query(mpYear, temp);
	}
	return 0;
}