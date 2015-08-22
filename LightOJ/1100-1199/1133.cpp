#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, a[105];
char o[2];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		while (m--) {
			scanf("%s", o);
			if (o[0] == 'S') {
				int D; scanf("%d", &D);
				for (int i = 0; i < n; ++i) a[i] += D;
			}
			if (o[0] == 'M') {
				int D; scanf("%d", &D);
				for (int i = 0; i < n; ++i) a[i] *= D;
			}
			if (o[0] == 'D') {
				int D; scanf("%d", &D);
				for (int i = 0; i < n; ++i) a[i] /= D;
			}
			if (o[0] == 'R') {
				for (int i = 0, j = n - 1; i < j; ++i, --j)
					swap(a[i], a[j]);
			}
			if (o[0] == 'P') {
				int X, Y; scanf("%d%d", &X, &Y);
				swap(a[X], a[Y]);
			}
		}
		printf("Case %d:\n%d", _, a[0]);
		for (int i = 1; i < n; ++i)
			printf(" %d", a[i]);
		printf("\n");
	}
	return 0;
}
