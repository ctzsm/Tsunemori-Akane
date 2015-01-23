#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

struct node {
	int x, y, step;
	node() {}
	node(int _x, int _y, int _s): x(_x), y(_y), step(_s) {}
	bool operator < (const node& a) const {
		return step > a.step;
	}
};
int N, M;
char board[305][305];
bool visited[305][305];
int main() {
	freopen("in", "r", stdin);
	while (~scanf("%d%d", &N, &M)) {
		if (N == 0 && M == 0) break;
		memset(visited, false, sizeof visited);
		for (int i = 1; i <= N; ++i) scanf("%s", board[i] + 1);
		priority_queue<node> q;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) 
				if (board[i][j] == 'Y') {
					q.push(node(j, i, 0));
					visited[i][j] = true;
				}
		}
		int ans = -1;
		while (!q.empty()) {
			node now = q.top(); q.pop();
			if (board[now.y][now.x] == 'T') {
				ans = now.step;
				break;
			}
			for (int i = 0; i < 4; ++i) {
				int x = now.x + dx[i], y = now.y + dy[i];
				if (x < 1 || x > M || y < 1 || y > N) continue;
				if (visited[y][x] || board[y][x] == 'R' || board[y][x] == 'S') continue;
				visited[y][x] = true;
				if (board[y][x] == 'B') q.push(node(x, y, now.step + 2));
				else q.push(node(x, y, now.step + 1));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}