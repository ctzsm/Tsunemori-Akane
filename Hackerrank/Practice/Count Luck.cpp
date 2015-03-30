#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int T, N, M, K;
int startx, starty, goalx, goaly;
bool visited[105][105];
char board[105][105];
bool dfs(int x, int y) {
	visited[y][x] = true;
	if (y == goaly && x == goalx)
		return true;
	bool flag = false;
	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		int nx = dx[i] + x, ny = dy[i] + y;
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
		if (visited[ny][nx] || board[ny][nx] == 'X') continue;
		cnt ++;
		flag = flag || dfs(nx, ny);
	}
	if (flag && cnt > 1) K--;
	return flag;
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; ++i) scanf("%s", board[i]);
		scanf("%d", &K);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j) {
				if (board[i][j] == 'M') 
					startx = j, starty = i;
				if (board[i][j] == '*')
					goalx = j, goaly = i;
			}
		memset(visited, false, sizeof visited);
		dfs(startx, starty);
		puts(K == 0 ? "Impressed" : "Oops!");
	}
	return 0;
}