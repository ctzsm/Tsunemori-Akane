// SG function can not apply to this problem
// We don't know the correct solution right now.

#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

int T, N, K, X;
bool h[70];
int sg[6][300][300];
int dx[] = {-1, -2};
int dy[] = {-2, -1};
void init() {
	memset(sg, -1, sizeof sg);
	for (int s = 1; s <= 5; ++s)
		for (int i = 0; i < 300; ++i)
			for (int j = 0; j < 300; ++j) {
				if (i == 0 || j == 0) {
					sg[s][i][j] = 0;
					continue;
				}
				memset(h, false, sizeof h);
				std::queue<std::pair<int, std::pair<int, int> > > q;
				q.push(std::make_pair(0, std::make_pair(i, j)));
				while (!q.empty()) {
					std::pair<int, std::pair<int, int> > now = q.front(); q.pop();
					int ns = now.first, ni = now.second.first, nj = now.second.second; 
					// if (s == 1 && i == 1 && j == 2) {
					// 	printf("%d %d %d\n", ns, ni, nj);
					// }
					if (ns > 0) h[sg[s][ni][nj]] = true;
					if (ns >= s) continue;
					for (int l = 0; l < 2; ++l) {
						int ci = ni + dx[l], cj = nj + dy[l];
						if (ci < 0 || cj < 0) continue;
						q.push(std::make_pair(ns + 1, std::make_pair(ci, cj)));
					}
				}
				for (int l = 0; l < 70; ++l) if (!h[l]) {
					sg[s][i][j] = l;
					break;
				}
			}
}
int d[32];
int main() {
	init();
	freopen("in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &N, &K, &X);
		memset(d, 0, sizeof d);
		for (int i = 0; i < N; ++i) {
			int x, y; scanf("%d%d", &x, &y);
			for (int j = 0; j < 32; ++j) {
				if (sg[X][x][y] & (1 << j)) d[j] ++;
			}
		}
		bool ans = false;
		for (int i = 0; i < 32; ++i) {
			// printf("%d", d[i] % (K + 1));
			if (d[i] % (K + 1)) {
				ans = true;
				break;
			}
		}
		printf(ans ? "First player wins\n" : "Second player wins\n");
	}
	return 0;
}