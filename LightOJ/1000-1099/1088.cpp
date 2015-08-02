#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, r, bc;
int a[100005], q[50005][2], b[200005];
int c[200005];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		scanf("%d%d", &n, &r);
		bc = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			b[bc++] = a[i];
		}
		for (int i = 0; i < r; ++i) {
			scanf("%d%d", &q[i][0], &q[i][1]);
			b[bc++] = q[i][0];
			b[bc++] = q[i][1];
		}
		sort(b, b + bc);
		bc = unique(b, b + bc) - b;
		memset(c, 0, (bc + 2) * sizeof(int));
		for (int i = 0; i < n; ++i) {
			int id = lower_bound(b, b + bc, a[i]) - b + 1;
			c[id] ++;
		}
		for (int i = 1; i <= bc; ++i) c[i] += c[i - 1];
		for (int i = 0; i < r; ++i) {
			int x = lower_bound(b, b + bc, q[i][0]) - b;
			int y = lower_bound(b, b + bc, q[i][1]) - b + 1;
			printf("%d\n", c[y] - c[x]);
		}
	}
	return 0;
}
