#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

char name[105][25];
int v[105], w[105];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int x, y, z; scanf("%s%d%d%d", name[i], &x, &y, &z);
			w[i] = v[i] = x * y * z;
		}
		sort(w, w + n);
		if (w[0] == w[1]) {
			printf("Case %d: no thief\n", _);
			continue;
		}
		int x = 0, y = 0;
		for (int i = 0; i < n; ++i) {
			if (v[i] == w[0]) y = i;
			if (v[i] == w[n - 1]) x = i;
		}
		printf("Case %d: %s took chocolate from %s\n", _, name[x], name[y]);
	}
	return 0;
}
