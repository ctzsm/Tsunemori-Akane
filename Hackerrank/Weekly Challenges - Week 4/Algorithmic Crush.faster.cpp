#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

const int maxn = 10000000;
int N, M;
long long a[maxn + 2];
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int l, r, k; scanf("%d%d%d", &l, &r, &k);
		a[l] += k;
		a[r + 1] -= k;
	}
	long long ans = 0;
	for (int i = 1; i <= N; ++i) {
		a[i] += a[i - 1];
		ans = std::max(ans, a[i]);
	}
	printf("%lld\n", ans);
	return 0;
}