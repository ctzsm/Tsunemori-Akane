#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int can[105][105], com[105][105];
int scom[105][105];
int match[205], used[205];
void solve() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &can[i][j]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &com[i][j]);
			scom[i][com[i][j]] = n - j;
		}
	}
	memset(match, -1, sizeof match);
	memset(used, 0, sizeof used);
	int tot = 0;
	while (tot != n) {
		for (int i = 1; i <= n; ++i) {
			if (used[i]) continue;
			for (int j = 0; j < n; ++j) {
				if (!used[can[i][j]]) {
					match[i] = can[i][j];
					match[can[i][j]] = i;
					used[i] = used[can[i][j]] = 1;
					tot += 1;
					break;
				} else {
					int y = can[i][j] - n;
					int ip = match[can[i][j]];
					if (scom[y][ip] < scom[y][i]) {
						match[i] = can[i][j];
						match[can[i][j]] = i;
						match[ip] = -1;
						used[ip] = 0;
						used[i] = 1;
						break;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		printf(" (%d %d)", i, match[i]);
	printf("\n");
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:", _);
		solve();
	}
	return 0;
}
