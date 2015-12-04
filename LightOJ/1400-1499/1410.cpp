#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int x[777], y[777], d[500000];
int solve() {
	int n, p = 0; scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d%d", x + i, y + i);
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			d[p++] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
	d[p++] = 0;
	sort(d, d + p);
	return unique(d, d + p) - d;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
