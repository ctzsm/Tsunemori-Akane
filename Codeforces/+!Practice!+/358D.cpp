#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 3005;
int n, a[maxn], b[maxn], c[maxn];
int f[maxn], g[maxn]; // first, second
int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) scanf("%d", b + i);
	for (int i = 1; i <= n; ++i) scanf("%d", c + i);
	f[n] = a[n], g[n] = b[n];
	for (int i = n - 1; i >= 1; --i) {
		f[i] = max(f[i + 1] + b[i], g[i + 1] + a[i]);
		g[i] = max(f[i + 1] + c[i], g[i + 1] + b[i]);
	}
	printf("%d\n", f[1]);
	return 0;
}
