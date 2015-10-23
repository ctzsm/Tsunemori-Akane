#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <algorithm>

using namespace std;

const int oo = 0x3f3f3f3f;
int n, W;
int p[105], w[105], v[10005];
void solve(int _) {
	scanf("%d%d", &n, &W);
	for (int i = 0; i < n; ++i) {
		int c; scanf("%d%d%d", p + i, &c, w + i);
		W -= c * w[i];
	}
	printf("Case %d: ", _);
	if (W < 0) {
		puts("Impossible");
		return;
	}
	for (int i = 1; i <= W; ++i) v[i] = -oo;
	for (int i = 0; i < n; ++i) {
		for (int j = w[i]; j <= W; ++j)
			v[j] = max(v[j], v[j - w[i]] + p[i]);
	}
	printf("%d\n", *max_element(v, v + W + 1));
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) solve(_);
	return 0;
}
