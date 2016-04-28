#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

string a[2], b[2];
string who, rec;
const char DIR[2][10] = {"Left", "Right"};
int w, cnt[2], scnt[2], x;
void get_who(string a[], int s) {
	int id = 0, dir = 0;
	if (s) {
		id = ((s - 1) % 6) < 3;
		dir = ((s - 1) % 4) < 2;
	}
	printf("%s %s", a[id].c_str(), DIR[dir]);
}
int main() {
	// freopen("in", "r", stdin);
	cin >> a[0] >> a[1];
	cin >> b[0] >> b[1];
	cin >> who >> w;
	cin >> rec;
	x = who == "A" ? 0 : 1;
	for (int i = 0; i < rec.size(); ++i) {
		if (x == 0) {
			get_who(a, scnt[0]);
			printf(" %d-%d\n", cnt[0], cnt[1]);
		} else {
			get_who(b, scnt[1]);
			printf(" %d-%d\n", cnt[1], cnt[0]);
		}
		scnt[x] ++;
		if (rec[i] == 'R')
			x ^= 1;
		cnt[x] ++;
		if (cnt[x] >= w) {
			printf("Team %c wins!\n", x == 0 ? 'A' : 'B');
			break;
		}
	}
	return 0;
}
