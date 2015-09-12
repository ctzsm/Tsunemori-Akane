#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int oo = 0x3f3f3f3f;
struct node {
	int i, j;
	node() {}
	node(int i, int j): i(i), j(j) {}
};
int R, C, t[2][205][205];
char b[205][205];
void bfs(char c, int id) {
	queue<node> q;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) {
			if (b[i][j] == c) {
				q.push(node(i, j));
				t[id][i][j] = 0;
			}
		}
	while (!q.empty()) {
		node now = q.front(); q.pop();
		for (int k = 0; k < 4; ++k) {
			int ni = now.i + dx[k], nj = now.j + dy[k];
			if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
			if (t[id][ni][nj] != oo || b[ni][nj] == '#') continue;
			q.push(node(ni, nj));
			t[id][ni][nj] = t[id][now.i][now.j] + 1;
		}
	}
}
void solve() {
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; ++i) scanf("%s", b[i]);
	memset(t, 0x3f, sizeof t);
	bfs('F', 0); bfs('J', 1);
	int ans = oo;
	for (int i = 0; i < R; ++i) {
		if (t[1][i][0] < t[0][i][0]) ans = min(ans, t[1][i][0]);
		if (t[1][i][C - 1] < t[0][i][C - 1]) ans = min(ans, t[1][i][C - 1]);
	}
	for (int i = 0; i < C; ++i) {
		if (t[1][0][i] < t[0][0][i]) ans = min(ans, t[1][0][i]);
		if (t[1][R - 1][i] < t[0][R - 1][i]) ans = min(ans, t[1][R - 1][i]);
	}
	if (ans != oo) printf("%d\n", ans + 1);
	else printf("IMPOSSIBLE\n");
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)  {
		printf("Case %d: ", _);
		solve();
	}
	return 0;
}
