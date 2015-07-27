#include <queue>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
int n;
char board[12][12];
PII pos[30];
bool visited[12][12];
int bfs(PII s, PII e) {
	memset(visited, false, sizeof visited);
	queue<PIII> q;
	q.push(make_pair(0, s));
	visited[s.first][s.second] = true;
	while (!q.empty()) {
		PIII now = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int x = now.second.first + dx[i];
			int y = now.second.second + dy[i];
			if (x < 0 || x >= n || y < 0 || y >= n) continue;
			if (x == e.first && y == e.second) return now.first + 1;
			if (visited[x][y] || board[x][y] != '.') continue;
			visited[x][y] = true;
			q.push(make_pair(now.first + 1, make_pair(x, y)));
		}
	}
	return -1;
}
void solve() {
	scanf("%d", &n);
	int m = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%s", board[i]);
		for (int j = 0; j < n; ++j) {
			if (isalpha(board[i][j])) {
				pos[board[i][j] - 'A'] = make_pair(i, j);
				m = max(m, board[i][j] - 'A');
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		int dis = bfs(pos[i - 1], pos[i]);
		if (dis == -1) {
			printf("Impossible\n");
			return;
		}
		ans += dis;
		PII& pre = pos[i - 1];
		board[pre.first][pre.second] = '.';
	}
	printf("%d\n", ans);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		solve();
	}
	return 0;
}
