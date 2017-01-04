#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, a[505][505], r[505];
long long ans[505];
bool in[505];
int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &r[i]);
	for (int k = n; k > 0; --k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (a[i][j] > a[i][r[k]] + a[r[k]][j])
					a[i][j] = a[i][r[k]] + a[r[k]][j];
			}
		}
		in[r[k]] = true;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j) continue;
				if (in[i] && in[j])
					ans[k] += a[i][j];
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%lld ", ans[i]);
	printf("\n");
	return 0;
}
