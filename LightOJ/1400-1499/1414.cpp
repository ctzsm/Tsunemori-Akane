#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

char s[2][20];
int day[2], year[2], c[2];
int check(int i) {
	if (s[i][0] == 'J' && s[i][1] == 'a') return -1;
	if (s[i][0] == 'F' && day[i] < 29) return -1;
	if (s[i][0] == 'F' && day[i] == 29) return 0;
	return 1;
}
bool leap(int i) {
	if (year[i] % 100 == 0) return year[i] % 400 == 0;
	return year[i] % 4 == 0;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		for (int i = 0; i < 2; ++i) {
			scanf("%s%d,%d", s[i], day + i, year + i);
			c[i] = year[i] / 4 - year[i] / 100 + year[i] / 400;
		}
		int ans = c[1] - c[0];
		if (year[0] == year[1]) {
			if (check(0) <= 0 && check(1) >= 0 && leap(0))
				ans ++;
		} else {
			if (check(0) <= 0 && leap(0)) ans ++;
			if (check(1) < 0 && leap(1)) ans --;
		}
		printf("Case %d: %d\n", _, ans);
	}
	return 0;
}
