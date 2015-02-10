#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

int T, N, V, v[1005], w[1005], f[1005];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &V);
		for (int i = 0; i < N; ++i) scanf("%d", &v[i]);
		for (int i = 0; i < N; ++i) scanf("%d", &w[i]);
		memset(f, false, sizeof f);
		for (int i = 0; i < N; ++i) {
			for (int j = V; j >= w[i]; --j)
				f[j] = max(f[j], f[j - w[i]] + v[i]);
		}
		int ans = 0;
		for (int i = V; i >= 0; --i) ans = max(ans, f[i]);
		printf("%d\n", ans);
	}
	return 0;
}