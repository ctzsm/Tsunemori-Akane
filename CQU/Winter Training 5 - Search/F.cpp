#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int N, M;
int b[105][105], f[105][105];
vector<pair<int, int> > w[10005];
vector<int> h;
int main() {
	freopen("in", "r", stdin);
	while (~scanf("%d%d", &N, &M)) {
		h.clear();
		for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
			scanf("%d", &b[i][j]);
			h.push_back(b[i][j]);
		}
		sort(h.begin(), h.end());
		h.resize(unique(h.begin(), h.end()) - h.begin());
		for (int i = 0; i <= *h.rbegin(); ++i) w[i].clear();
		for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j)
			w[b[i][j]].push_back(make_pair(j, i));
		int ans = 0;
		for (int i = 0; i < (int)h.size(); ++i) {
			int height = h[i];
			for (int j = 0; j < (int)w[height].size(); ++j) {
				int x = w[height][j].first, y = w[height][j].second;
				f[y][x] = 1;
				for (int k = 0; k < 4; ++k) {
					int nx = x + dx[k], ny = y + dy[k];
					if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
					if (b[ny][nx] >= b[y][x]) continue;
					f[y][x] = max(f[y][x], f[ny][nx] + 1);
				}
				ans = max(ans, f[y][x]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}