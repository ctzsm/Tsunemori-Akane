#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int W, H;
char board[25][25];
bool visited[25][25];
int main() {
	freopen("in", "r", stdin);
	while (~scanf("%d%d", &W, &H)) {
		if (W == 0 && H == 0) break;
		memset(board, '#', sizeof board);
		memset(visited, false, sizeof visited);
		int startx = 0, starty = 0;
		for (int i = 1; i <= H; ++i) scanf("%s", board[i] + 1);
		for (int i = 1; i <= H; ++i)
			for (int j = 1; j <= W; ++j)
				if (board[i][j] == '@')
					startx = j, starty = i;
		queue<pair<int, int> > q;
		q.push(make_pair(startx, starty));
		visited[starty][startx] = true;
		while (!q.empty()) {
			pair<int, int> now = q.front(); q.pop();
			for (int i = 0; i < 4; ++i) {
				int x = now.first + dx[i], y = now.second + dy[i];
				if (!visited[y][x] && board[y][x] == '.') {
					visited[y][x] = true;
					q.push(make_pair(x, y));
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= H; ++i) for (int j = 1; j <= W; ++j)
			if (visited[i][j]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}