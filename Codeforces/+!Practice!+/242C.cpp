#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

const long long maxn = 1000000000;
const int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy[] = {1, -1, 1, 0, -1, 1, 0, -1};

set<long long> h;
int n, sx, sy, ex, ey;
int BFS() {
	queue<PIII> q;
	q.push({0, {sy, sx}});
	h.erase(sy * maxn + sx);
	long long e = ey * maxn + ex;
	while (!q.empty()) {
		PIII cur = q.front(); q.pop();
		int cy = cur.second.first, cx = cur.second.second;
		for (int i = 0; i < 8; ++i) {
			int y = cy + dy[i], x = cx + dx[i];
			long long id = y * maxn + x;
			if (h.find(id) == h.end())
				continue;
			h.erase(id);
			if (id == e)
				return cur.first + 1;
			q.push({cur.first + 1, {y, x}});
		}
	}
	return -1;
}
int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d%d%d", &sy, &sx, &ey, &ex);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int r, a, b;
		scanf("%d%d%d", &r, &a, &b);
		for (int j = a; j <= b; ++j)
			h.insert(r * maxn + j);
	}
	printf("%d\n", BFS());
	return 0;
}
