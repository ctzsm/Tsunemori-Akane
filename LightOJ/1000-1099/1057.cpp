#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, n, m;
char b[21][21];
int f[1 << 16][16];
int dis[16][16];
int distance(int i, int j, vector<pair<int, int> >& v) {
	return max(abs(v[i].first - v[j].first), abs(v[i].second - v[j].second));
}
int solve() {
	scanf("%d%d", &n, &m);
	int x = -1;
	vector<pair<int, int> > v;
	for (int i = 0; i < n; ++i) {
		scanf("%s", b[i]);
		for (int j = 0; j < m; ++j) {
			if (b[i][j] == 'x' || b[i][j] == 'g') {
				v.push_back(make_pair(i, j));
				if (b[i][j] == 'x') x = v.size() - 1;
			}
		}
	}
	for (int i = 0; i < v.size(); ++i)
		for (int j = 0;j < v.size(); ++j)
			dis[i][j] = distance(i, j, v);
	int l = 1 << v.size();
	memset(f, 0x3f, sizeof f);
	f[1 << x][x] = 0;
	for (int mask = 1; mask < l; ++mask) {
		for (int j = 0; j < v.size(); ++j) {
			if (mask & (1 << j)) continue;
			int mask2 = mask | (1 << j);
			for (int k = 0; k < v.size(); ++k) {
				if (mask & (1 << k)) {
					f[mask2][j] = min(f[mask2][j], f[mask][k] + dis[j][k]);
				}
			}
		}
	}
	int res = 0x3f3f3f3f;
	for (int i = 0; i < v.size(); ++i)
		res = min(res, f[l - 1][i] + dis[i][x]);
	return res;
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
