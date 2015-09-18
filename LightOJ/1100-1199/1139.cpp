#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int s[9], l;
inline int ph(int x, int y) {
	y -= 1;
	return abs(x / 3 - y / 3) + abs(x % 3 - y % 3);
}
bool dfs(int y, int x, int pre, int d, int hv) {
	if (d + hv > l) return false;
	if (hv == 0) return true;
	for (int i = 0, p = y * 3 + x; i < 4; ++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (i == pre || nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
		int np = ny * 3 + nx;
		int nh = hv - ph(np, s[np]) + ph(p, s[np]);
		swap(s[p], s[np]);
		if (dfs(ny, nx, i ^ 1, d + 1, nh)) return true;
		swap(s[p], s[np]);
	}
	return false;
}
bool check() {
	int inv = 0;
	for (int i = 0; i < 9; ++i)
		for (int j = i + 1; j < 9; ++j)
			if (s[i] && s[j] && s[i] > s[j]) inv ++;
	return !(inv & 1);
}
void solve() {
	int hv = 0, p = 0;
	for (int i = 0; i < 9; ++i) scanf("%d", s + i);
	if (!check()) { puts("impossible"); return; }
	for (int i = 0; i < 9; ++i) if (s[i]) hv += ph(i, s[i]); else p = i;
	for (l = 0; !dfs(p / 3, p % 3, -1, 0, hv); ++l);
	printf("%d\n", l);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		solve();
	}
	return 0;
}
