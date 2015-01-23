#include <bits/stdc++.h>

using namespace std;

int n, m;
long long a[2][100005];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[0][i]);
		a[1][i] = a[0][i];
	}
	sort(a[1] + 1, a[1] + n + 1);
	for (int j = 0; j < 2; ++j)
		for (int i = 1; i <= n; ++i) 
			a[j][i] += a[j][i - 1];
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int t, l, r; scanf("%d%d%d", &t, &l, &r);
		printf("%lld\n", a[t - 1][r] - a[t - 1][l - 1]);
	}
	return 0;
}