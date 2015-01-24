#include <bits/stdc++.h>

using namespace std;

const int oo = 0x3f3f3f3f;
int N, w[505][505], d[505][505];
long long cmp(pair<int, int>& a, pair<int, int>& b) {
	return 1LL * a.first * b.second - 1LL * a.second * b.first;
}
int main() {
	freopen("in", "r", stdin);
	memset(d, 0x3f, sizeof d);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) 
			scanf("%d", &w[i][j]);
	for (int i = 0; i <= N; ++i) w[i][i] = oo;
	for (int i = 0; i < N; ++i) 
		w[N][i] = 0, w[i][N] = oo;
	d[0][N] = 0;
	for (int k = 0; k <= N; ++k)
		for (int i = 0; i <= N; ++i)
			for (int j = 0; j <= N; ++j)
				d[k + 1][j] = min(d[k + 1][j], d[k][i] + w[i][j]);
	for (int k = 0; k <= N + 1; ++k) {
		for (int i = 0; i <= N; ++i) printf("d[%d][%d] = %d ", k, i, d[k][i]); printf("\n");
	}
	pair<int, int> ans = make_pair(oo, 1);
	for (int i = 0; i < N; ++i) {
		if (d[N][i] == oo) continue;
		pair<int, int> now = make_pair(-oo, 1);
		for (int k = 0; k < N; ++k) {
			if (d[k][i] == oo) continue;
			pair<int, int> nxt = make_pair(d[N + 1][i] - d[k][i], N + 1 - k);
			if (cmp(nxt, now) > 0) now = nxt;
		}
		if (cmp(ans, now) > 0)
			ans = now;
	}
	int gcd = __gcd(ans.first, ans.second);
	printf("%d/%d\n", ans.first / gcd, ans.second / gcd);
	return 0;
}