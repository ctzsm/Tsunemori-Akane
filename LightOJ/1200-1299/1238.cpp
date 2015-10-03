#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n, m;
char b[25][25];
bool visited[25][25];
int bfs(int y, int x) {
	memset(visited, false, sizeof visited);
	queue<pair<int, int> > q;
	q.push(make_pair(y * m + x, 0)); visited[y][x] = true;
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		int y = now.first / m, x = now.first % m;
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx] || b[ny][nx] == '#' || b[ny][nx] == 'm') continue;
			visited[ny][nx] = true;
			if (b[ny][nx] == 'h') return now.second + 1;
			q.push(make_pair(ny * m + nx, now.second + 1));
		}
	}
	return 0;
}
int solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%s", b[i]);
	int res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if ('a' <= b[i][j] && b[i][j] <= 'c')
				res = max(res, bfs(i, j));
	return res;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
