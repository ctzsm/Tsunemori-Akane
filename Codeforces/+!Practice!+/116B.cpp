#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

char grid[15][15];
int cnt[15][15];
int n, m, ans = 0;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main(int argc, char** argv) {
	freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%s", grid[i] + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (grid[i][j] == 'W') {
				for (int l = 0; l < 4; ++l) {
					if (grid[i + dx[l]][j + dy[l]] == 'P')
						cnt[i][j]++;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (cnt[i][j] == 1) {
				for (int l = 0; l < 4; ++l) {
					if (grid[i + dx[l]][j + dy[l]] == 'P') {
						grid[i + dx[l]][j + dy[l]] = '.';
						grid[i][j] = '.';
					}
				}
				cnt[i][j] = 0;
				ans++;
			}
		}
	}
	memset(cnt, 0, sizeof (cnt));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (grid[i][j] == 'W') {
				for (int l = 0; l < 4; ++l) {
					if (grid[i + dx[l]][j + dy[l]] == 'P')
						cnt[i][j]++;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j)
			if (cnt[i][j]) ans++;
	printf("%d\n", ans);
	return 0;
}

