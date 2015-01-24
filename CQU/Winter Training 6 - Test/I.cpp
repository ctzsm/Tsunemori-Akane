#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int w, h, nCase = 1;
char board[100][100];
bool visited[100][100];
bool check(int x, int y) {
	if (x < 0 || x > w + 1 || y < 0 || y > h + 1 || board[y][x] == 'X') return false;
	return true;
}
int bfs(int sx, int sy, int gx, int gy) {
	if (sx == gx && sy == gy)
		return 0;
	memset(visited, false, sizeof visited);
	queue<pair<pair<int, int>, int> >q;
	q.push(make_pair(make_pair(sx, sy), 0));
	visited[sy][sx] = true;
	while (!q.empty()) {
		pair<pair<int, int>, int> now = q.front(); q.pop();
		// printf("%d %d\n", now.first.first, now.first.second);
		for (int i = 0; i < 4; ++i) {
			int x = now.first.first + dx[i], y = now.first.second + dy[i];
			while (check(x, y)) {
				if (!visited[y][x]) 
					q.push(make_pair(make_pair(x, y), now.second + 1));
				visited[y][x] = true;
				x += dx[i], y += dy[i];
			}
			if (board[y][x] == 'X') {
				if (x == gx && y == gy)
					return now.second + 1;
			}
		}
	}
	return -1;
}
int main() {
	freopen("in", "r", stdin);
	while (scanf("%d%d", &w, &h)) {
		if (w == 0 && h == 0) break;
		printf("Board #%d:\n", nCase++);
		fgets(board[0], 1000, stdin);
		memset(board, 0, sizeof board);
		for (int i = 1; i <= h; ++i) fgets(board[i] + 1, 1024, stdin);
		// for (int i = 1; i <= h; ++i) {
		// 	for (int j = 1; j <= w; ++j) putchar(board[i][j]);
		// 	putchar('\n');
		// }
		// printf("\n");
		int nAns = 1;
		while (true) {
			int sx, sy, gx, gy;
			scanf("%d%d%d%d", &sx, &sy, &gx, &gy);
			if (sx == 0 && sy == 0 && gx == 0 && gy == 0) break;
			printf("Pair %d: ", nAns++);
			int ans = bfs(sx, sy, gx, gy);
			if (ans == -1) 
				printf("impossible.\n");
			else
				printf("%d segments.\n", ans);
		}
		printf("\n");
	}
	return 0;
}