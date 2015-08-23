#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
long long a[105][105];
int u[10005], v[10005];
long long c[10005];
void main2() {
	scanf("%d%d", &n, &m);
	memset(a, 0x3f, sizeof a);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%lld", &u[i], &v[i], &c[i]);
		int U = u[i], V = v[i];
		a[V][U] = a[U][V] = min(a[U][V], c[i]);
	}
	for (int i = 0; i < n; ++i) a[i][i] = 0;
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (a[i][j] > a[i][k] + a[k][j])
					a[i][j] = a[i][k] + a[k][j];
	for (int i = 0; i < m; ++i)
		if (c[i] != a[u[i]][v[i]])
			printf("%d\n", i);
}
int main() {
	freopen("C-large-practice.in", "r", stdin);
	freopen("C-large-practice.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d:\n", _);
		main2();
	}
	return 0;
}
