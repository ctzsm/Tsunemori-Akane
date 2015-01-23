#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, -1, -1, -1, 1, 1, 1};
const int dy[] = {-1, 1, -1, 0, 1, -1, 0, 1};
int m, n;
char board[105][105];
bool visited[105][105];
void dfs(int i, int j) {
	if (visited[i][j]) return;
	if (board[i][j] != '@') return;
	visited[i][j] = true;
	for (int k = 0; k < 8; ++k) 
		dfs(i + dx[k], j + dy[k]);
}
int main() {
	freopen("in", "r", stdin);
	while (~scanf("%d%d", &m, &n)) {
		if (m == 0) break;
		memset(board, '*', sizeof board);
		memset(visited, false, sizeof visited);
		for (int i = 1; i <= m; ++i) scanf("%s", board[i] + 1);
		int ans = 0;
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				if (!visited[i][j] && board[i][j] == '@') {
					dfs(i, j);
					ans ++;
				}
		printf("%d\n", ans);
	}
	return 0;
}