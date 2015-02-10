#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

int n, a[100005][11];
int main() {
	freopen("in", "r", stdin);
	while (scanf("%d", &n), n) {
		memset(a, 0, sizeof a);
		int T = 0;
		for (int i = 0; i < n; ++i) {
			int x, t; scanf("%d%d", &x, &t);
			T = max(T, t);
			a[t][x] ++;
		}
		for (int i = T - 1; i >= 0; --i)
			for (int j = 0; j <= 10; ++j) {
				int who = 0;
				for (int k = -1; k <= 1; ++k) {
					int x = j + k;
					if (x >= 0 && x <= 10) {
						who = max(who, a[i + 1][x]);
					}
				}
				a[i][j] += who;
			}
		printf("%d\n", a[0][5]);
	}
	return 0;
}