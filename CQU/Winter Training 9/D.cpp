#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
const int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};
char s[5], e[5];
bool visited[10][10];
typedef pair<pair<int, int>, int> PIII;
int bfs() {
	int sx = s[0] - 'a', sy = s[1] - '1';
	int ex = e[0] - 'a', ey = e[1] - '1';
	memset(visited, false, sizeof visited);
	visited[sy][sx] = true;
	queue<PIII> q;
	q.push(make_pair(make_pair(sx, sy), 0));
	while (!q.empty()) {
		PIII now = q.front(); q.pop();
		if (now.first.first == ex && now.first.second == ey) 
			return now.second;
		for (int i = 0; i < 8; ++i) {
			int x = now.first.first + dx[i];
			int y = now.first.second + dy[i];
			if (x < 0 || x >= 8 || y < 0 || y >= 8 || visited[y][x]) continue;
			visited[y][x] = true;
			q.push(make_pair(make_pair(x, y), now.second + 1));
		}
	}
	return -1;
}
int main() {
	freopen("in", "r", stdin);
	while (~scanf("%s%s", s, e))
		printf("To get from %s to %s takes %d knight moves.\n", s, e, bfs());
	return 0;
}