#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int> > PIII;
const int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
int n, m;
int ans[100][10][10];
char b[10][12];
bool visited[10][10];
void bfs(int x, int y, int K, int a[10][10]) {
	a[y][x] = 0; memset(visited, false, sizeof visited);
	queue<PIII> q;
	q.push(make_pair(0, make_pair(x, y)));
	visited[y][x] = true;
	while (!q.empty()) {
		int step = q.front().first;
		int j = q.front().second.first, i = q.front().second.second;
		a[i][j] = step ? (step - 1) / K + 1 : 0;
		q.pop();
		for (int k = 0; k < 8; ++k) {
			int x = dx[k] + j, y = dy[k] + i;
			if (x < 0 || x >= m || y < 0 || y >= n) continue;
			if (visited[y][x]) continue;
			q.push(make_pair(step + 1, make_pair(x, y)));
			visited[y][x] = true;
		}
	}
}
int solve() {
	scanf("%d%d", &n, &m);
	memset(ans, -1, sizeof ans);
	for (int i = 0; i < n; ++i) scanf("%s", b[i]);
	int cnt = 0, res = -1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (b[i][j] != '.')
				bfs(j, i, b[i][j] - '0', ans[cnt++]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			int sum = 0;
			for (int k = 0; k < cnt; ++k) {
				if (ans[k][i][j] == -1) {
					sum = -1;
					break;
				}
				sum += ans[k][i][j];
			}
			if (sum != -1 && (res == -1 || res > sum))
				res = sum;
		}
	return res;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
