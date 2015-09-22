#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, f[105], a[105], b[105];
bool check(int t) {
	memset(f, -1, sizeof f); f[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = m, l = t / a[i]; j >= 0; --j) {
			for (int k = 0; k <= j && k <= l && t - k * a[i] >= 0; ++k)
				if (f[j - k] != -1)
					f[j] = max(f[j], f[j - k] + (t - k * a[i]) / b[i]);
		}
		if (f[m] >= m) return true;
	}
	return f[m] >= m;
}
int solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d%d", a + i, b + i);
	int l = 0, r = min(50000, (a[0] + b[0]) * m);
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
