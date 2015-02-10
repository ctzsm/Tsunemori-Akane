#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

int N, v[55], c[55], cnt[250005];
bool f[250005];
int main() {
	freopen("in", "r", stdin);
	while (scanf("%d", &N)) {
		if (N < 0) break;
		int V = 0;
		for (int i = 0; i < N; ++i) {
			scanf("%d%d", &v[i], &c[i]);
			V += v[i] * c[i];
		}
		int tot = V;
		V /= 2;
		memset(f, false, sizeof f); f[0] = true;
		for (int i = 0; i < N; ++i) {
			if (c[i] == 1) {
				for (int j = V; j >= v[i]; --j) f[j] |= f[j - v[i]];
				continue;
			}
			if (c[i] * v[i] >= V) {
				for (int j = v[i]; j <= V; ++j) f[j] |= f[j - v[i]];
				continue;
			}
			for (int j = 0; j <= V; ++j) cnt[j] = 0;
			for (int j = v[i]; j <= V; ++j) 
				if (!f[j] && f[j - v[i]] && cnt[j - v[i]] < c[i]) {
					cnt[j] = cnt[j - v[i]] + 1;
					f[j] = true;
				}
		}
		for (int i = V; i >= 0; --i)
			if (f[i]) {
				printf("%d %d\n", tot - i, i);
				break;
			}
	}
	return 0;
}