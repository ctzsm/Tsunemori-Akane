#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, a[10005];
double b[10005], f[10005];
int main() {
	freopen("in", "r", stdin);
	while (scanf("%d%d", &n, &m)) {
		if (n == 0 && m == 0) break;
		for (int i = 0; i < m; ++i) scanf("%d%lf", &a[i], &b[i]);
		for (int i = 0; i <= n; ++i) f[i] = 1.0;
		for (int i = 0; i < m; ++i) 
			for (int j = n; j >= a[i]; --j)
				f[j] = min(f[j], f[j - a[i]] * (1.0 - b[i]));
		printf("%.1f%%\n", (1.0 - f[n]) * 100.0);
	}
	return 0;
}