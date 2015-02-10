#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

int n, m;
bool f[200005];
int A[105], C[105], cnt[200005];
int main() {
	freopen("in", "r", stdin);
	while (true) {
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) break;
		memset(f, false, sizeof f);
		f[0] = true;
		for (int i = 0; i < n; ++i) scanf("%d", &A[i]);
		for (int i = 0; i < n; ++i) scanf("%d", &C[i]);
		for (int i = 0; i < n; ++i) {
			if (C[i] == 1) {
				for (int j = m; j >= A[i]; --j) f[j] |= f[j - A[i]];
				continue;
			}
			if (C[i] * A[i] >= m) {
				for (int j = A[i]; j <= m; ++j) f[j] |= f[j - A[i]];
				continue;
			}
			for (int j = 0; j <= m; ++j) cnt[j] = 0;
			for (int j = A[i]; j <= m; ++j) 
				if (!f[j] && f[j - A[i]] && cnt[j - A[i]] < C[i]) {
					cnt[j] = cnt[j - A[i]] + 1;
					f[j] = true;
				}
		}
		int ans = 0;
		for (int i = 1; i <= m; ++i) ans += f[i];
		printf("%d\n", ans);
	}
	return 0;
}