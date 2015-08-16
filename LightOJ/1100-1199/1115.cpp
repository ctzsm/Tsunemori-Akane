#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n, m;
char b[55][55];
bool visited[55][55];
void bfs(char x) {
	queue<pair<int, int> > q, r;
	memset(visited, false, sizeof visited);
	for (int i = 0; i <= n + 1; ++i) {
		q.push(make_pair(i, 0));
		q.push(make_pair(i, m + 1));
		visited[i][0] = visited[i][m + 1] = true;
	}
	for (int i = 1; i <= m; ++i) {
		q.push(make_pair(0, i));
		q.push(make_pair(n + 1, i));
		visited[0][i] = visited[n + 1][i] = true;
	}
	while(!q.empty()) {
		pair<int, int> s = q.front(); q.pop();
		for (int k = 0; k < 4; ++k) {
			int i = s.first + dx[k];
			int j = s.second + dy[k];
			if (i < 0 || i > n + 1 || j < 0 || j > m + 1)
				continue;
			if (visited[i][j]) continue;
			visited[i][j] = true;
			if (b[i][j] == x)
				r.push(make_pair(i, j));
			else
				q.push(make_pair(i, j));
		}
	}
	while (!r.empty()) {
		pair<int, int> s = r.front(); r.pop();
		for (int k = 0; k < 4; ++k) {
			int i = s.first + dx[k];
			int j = s.second + dy[k];
			if (i < 1 || i > n || j < 1 || j > m)
				continue;
			if (visited[i][j]) continue;
			visited[i][j] = true;
			b[i][j] = x;
			r.push(make_pair(i, j));
		}
	}
}
void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%s", b[i] + 1);
	for (int i = 0; i < 26; ++i)
		bfs('A' + i);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			putchar(b[i][j]);
		putchar('\n');
	}
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		solve();
	}
	return 0;
}
