#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <algorithm>

using namespace std;

int a[55], c[2][250005];
void solve(int _) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	int sum = accumulate(a, a + n, 0) >> 1;
	memset(c, -1, sizeof c); c[0][0] = 0;
	int cur = 1, pre = 0;
	for (int i = 0, t = 0; i < n; ++i) {
		for (int j = 0; j <= t; ++j) {
			if (c[pre][j] == -1) continue;
			int k = abs(j - a[i]), l = j + a[i];
			c[cur][j] = max(c[cur][j], c[pre][j]);
			if (k <= sum) c[cur][k] = max(c[cur][k], c[pre][j] + a[i]);
			if (l <= sum) c[cur][l] = max(c[cur][l], c[pre][j] + a[i]);
		}
		swap(cur, pre);
		t = min(t + a[i], sum);
	}
	if (c[pre][0]) printf("Case %d: %d\n", _, c[pre][0] >> 1);
	else printf("Case %d: impossible\n", _);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) solve(_);
	return 0;
}
