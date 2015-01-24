#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int N, w[505][505];
int main() {
	freopen("in", "r", stdin);
	while (scanf("%d", &N)) {
		if (N == 0) break;
		memset(w, 0x3f, sizeof w);
		for (int i = 0; i < N; ++i) {
			int c = 0; scanf("%d", &c);
			for (int j = 0; j < c; ++j) {
				int u, x; scanf("%d%d", &u, &x);
				w[i][u - 1] = x;
			}
		}
		for (int k = 0; k < N; ++k) 
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j)
					w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
		int id = 0, ans = 0x3f3f3f3f;
		for (int i = 0; i < N; ++i) {
			int now = 0;
			for (int j = 0; j < N; ++j) {
				if (i == j) continue;
				now = max(now, w[i][j]);
			}
			if (ans > now) {
				id = i + 1, ans = now;
			}
		}
		printf("%d %d\n", id, ans);
	}
	return 0;
}