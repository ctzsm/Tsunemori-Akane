#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
struct node {
	pair<int, int> p[3];
}x;
int n;
char board[11][12];
bool visited[100][100][100];
bool isgoal(const node& x) {
	for (int i = 0; i < 3; ++i) {
		const pair<int, int>& p = x.p[i];
		if (board[p.first][p.second] != 'X') return false;
	}
	return true;
}
bool check(const node& x) {
	int pos[3];
	for (int i = 0; i < 3; ++i)
		pos[i] = (x.p[i].first - 1) * n + (x.p[i].second - 1);
	if (visited[pos[0]][pos[1]][pos[2]])
		return false;
	return true;
}
void set_flag(const node& x) {
	int pos[3];
	for (int i = 0; i < 3; ++i)
		pos[i] = (x.p[i].first - 1) * n + (x.p[i].second - 1);
	visited[pos[0]][pos[1]][pos[2]] = true;
}
bool moved[3];
void move(node& now, node& nxt, int dir, int i) {
	if (moved[i]) return;
	moved[i] = true;
	int x = now.p[i].first + dx[dir];
	int y = now.p[i].second + dy[dir];
	if (x <= 0 || x > n || y <= 0 || y > n || board[x][y] == '#')
		return;
	pair<int, int> p = make_pair(x, y);
	for (int k = 0; k < 3; ++k) {
		if (now.p[k] == p) {
			move(now, nxt, dir, k);
			if (nxt.p[k] == p) return;
		}
	}
	nxt.p[i] = p;
}
int bfs() {
	memset(visited, false, sizeof visited);
	set_flag(x);
	queue<pair<int, node> > q; q.push(make_pair(0, x));
	while (!q.empty()) {
		pair<int, node> status = q.front(); q.pop();
		node& now = status.second;
		for (int k = 0; k < 4; ++k) {
			node nxt = now;
			memset(moved, false, sizeof moved);
			for (int i = 0; i < 3; ++i)
				move(now, nxt, k, i);
			if (!check(nxt)) continue;
			if (isgoal(nxt)) return status.first + 1;
			set_flag(nxt);
			q.push(make_pair(status.first + 1, nxt));
		}
	}
	return -1;
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%s", board[i] + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (board[i][j] == '.' || board[i][j] == '#' || board[i][j] == 'X')
				continue;
			else
				x.p[board[i][j] - 'A'] = make_pair(i, j);
		}
	}
	int res = bfs();
	if (res == -1) {
		printf("trapped\n");
		return;
	}
	printf("%d\n", res);
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
