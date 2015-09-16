#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int f[10005];
int sg(int x) {
	if (f[x] != -1) return f[x];
	bool g[205]; memset(g, false, sizeof g);
	for (int i = 1; i < x - i; ++i) {
		g[sg(i) ^ sg(x - i)] = true;
	}
	for (int i = 0; ; ++i)
		if (!g[i])
			return f[x] = i;
	return -1;
}
int main() {
	freopen("in", "r", stdin);
	memset(f, -1, sizeof f); f[1] = f[2] = 0;
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n; scanf("%d", &n);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int x; scanf("%d", &x);
			ans ^= sg(x);
		}
		printf("Case %d: %s\n", _, ans ? "Alice" : "Bob");
	}
	return 0;
}
