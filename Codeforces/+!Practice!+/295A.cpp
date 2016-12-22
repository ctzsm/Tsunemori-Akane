#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int n, m, k;
long long a[maxn + 5], b[maxn + 5], o[maxn + 5];
int l[maxn + 5], r[maxn + 5], d[maxn + 5];
int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i) scanf("%lld", a + i);
	for (int i = 0; i < m; ++i)
		scanf("%d%d%d", l + i, r + i, d + i);
	for (int i = 0; i < k; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		o[x - 1] ++, o[y] --;
	}
	for (int i = 1; i < m; ++i) o[i] += o[i - 1];
	for (int i = 0; i < m; ++i) {
		b[l[i] - 1] += d[i] * o[i];
		b[r[i]] -= d[i] * o[i];
	}
	for (int i = 1; i < n; ++i) b[i] += b[i - 1];
	for (int i = 0; i < n; ++i)
		printf("%lld ", a[i] + b[i]);
	return 0;
}
