#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
	int x, y, step;
	node() {
	}
	node(int _x, int _y, int _s): x(_x), y(_y), step(_s) {
	}
};

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

char board[105][105];
bool flag[105][105][4];
bool visited[105][105][4];
// <^>v
bool go(char x) {
	if (x == '#' ||
	        x == '<' || x == '^' ||
	        x == '>' || x == 'v')
		return false;
	return true;
}
void turn(char &x) {
	if (x == '<') x = '^';
	else if (x == '^') x = '>';
	else if (x == '>') x = 'v';
	else if (x == 'v') x = '<';
}
void solve() {
	int m, n; scanf("%d%d", &m, &n);
	memset(board, '#', sizeof board);
	memset(flag, false, sizeof flag);
	memset(visited, false, sizeof visited);
	int sx, sy, gx, gy;
	for (int i = 1; i <= m; ++i) scanf("%s", board[i] + 1);
	for (int i = 1; i <= m; ++i) board[i][n + 1] = '#';
	for (int t = 0; t < 4; ++t)
		for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) {
			if (board[i][j] == 'S') sx = j, sy = i;
			if (board[i][j] == 'G') gx = j, gy = i;
			if (go(board[i][j])) continue;
			flag[i][j][t] = true;
			if (board[i][j] == '<') {
				int k = j - 1;
				while (go(board[i][k])) {
					flag[i][k][t] = true;
					k --;
				}
			} else if (board[i][j] == '^') {
				int k = i - 1;
				while (go(board[k][j])) {
					flag[k][j][t] = true;
					k --;
				}
			} else if (board[i][j] == '>') {
				int k = j + 1;
				while (go(board[i][k])) {
					flag[i][k][t] = true;
					k ++;
				}
			} else if (board[i][j] == 'v') {
				int k = i + 1;
				while (go(board[k][j])) {
					flag[k][j][t] = true;
					k ++;
				}
			}
			turn(board[i][j]);
		}
	queue<node> q;
	q.push(node(sx, sy, 0));
	visited[sy][sx][0] = true;
	while (!q.empty()) {
		node now = q.front(); q.pop();
		if (now.x == gx && now.y == gy) {
			printf("%d\n", now.step);
			return;
		}
		for (int i = 0; i < 4; ++i) {
			int x = now.x + dx[i];
			int y = now.y + dy[i];
			if (go(board[y][x]) && !flag[y][x][(now.step + 1) % 4] && !visited[y][x][(now.step + 1) % 4]) {
				q.push(node(x, y, now.step + 1));
				visited[y][x][(now.step + 1) % 4] = true;
			}
		}
	}
	printf("impossible\n");
}
int main() {
	// freopen("in", "r", stdin);
	freopen("laser_maze.txt", "r", stdin);
	freopen("laser_maze.out", "w", stdout);
	int __; scanf("%d", &__);
	for (int _ = 1; _ <= __; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}