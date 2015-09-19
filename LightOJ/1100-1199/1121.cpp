#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

const char imp[] = "This puzzle is not solvable.";
const char dir[] = "DLRU";
const int dx[] = {0, -1, 1, 0};
const int dy[] = {1, 0, 0, -1};
char ans[90];
int s[16], l;
inline int ph(int x, int y) {
	y -= 1;
	return abs((x >> 2) - (y >> 2)) + abs((x & 3) - (y & 3));
}
bool dfs(int y, int x, int pre, int d, int hv) {
	if (d + hv > l) return false;
	if (hv == 0) { return true; }
	for (int i = 0, p = y * 4 + x; i < 4; ++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (i == pre || nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
		int np = ny * 4 + nx;
		int nh = hv - ph(np, s[np]) + ph(p, s[np]);
		std::swap(s[p], s[np]);
		if (dfs(ny, nx, 3 - i, d + 1, nh)) {
			ans[d] = dir[i]; return true;
		}
		std::swap(s[p], s[np]);
	}
	return false;
}
bool check() {
	int inv = 0, row = 0;
	for (int i = 0; i < 16; ++i) {
		if (!s[i]) row = i >> 2;
		for (int j = i + 1; j < 16; ++j)
			if (s[i] && s[j] && s[i] > s[j]) inv ++;
	}
	return (inv + row) & 1;
}
void solve() {
	int p = 0, hv = 0;
	for (int i = 0; i < 16; ++i) scanf("%d", s + i);
	for (int i = 0; i < 16; ++i) if (!s[i]) p = i; else hv += ph(i, s[i]);
	if (!check()) { puts(imp); return; }
	for (l = 0; l < 36; ++l)
		if (dfs(p >> 2, p & 3, -1, 0, hv))
			break;
	if (l < 36) {
		ans[l] = 0; puts(ans);
	} else {
		puts(imp);
	}
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
