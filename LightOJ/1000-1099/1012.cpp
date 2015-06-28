#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int T, n, m;
char board[25][25];
bool visited[25][25];
int dfs(int x, int y) {
	visited[y][x] = true;
	int res = 1;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (visited[ny][nx] || board[ny][nx] == '#') continue;
		res += dfs(nx, ny);
	}
	return res;
}
int solve() {
	scanf("%d%d", &m, &n);
	memset(visited, false, sizeof visited);
	int ix = -1, iy = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%s", board[i]);
		for (int j = 0; j < m; ++j)
			if (board[i][j] == '@')
				iy = i, ix = j;
	}
	return dfs(ix, iy);
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
