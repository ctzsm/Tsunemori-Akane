#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <algorithm>

using namespace std;

int n, m[105];
double P, p[105], f[10005];
int solve() {
	scanf("%lf%d", &P, &n);
	for (int i = 0; i < n; ++i) scanf("%d%lf", &m[i], &p[i]);
	int V = accumulate(m, m + n, 0);
	for (int i = 1; i <= V; ++i) f[i] = 1.0;
	for (int i = 0; i < n; ++i) {
		for (int j = V; j >= m[i]; --j)
			f[j] = min(f[j], 1.0 - (1.0 - f[j - m[i]]) * (1.0 - p[i]));
	}
	for (int i = V; i >=0; --i) {
		if (f[i] < P) return i;
	}
	return 0;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
