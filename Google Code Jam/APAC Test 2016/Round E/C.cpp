#include <bits/stdc++.h>

using namespace std;

long double main2() {
	int n, x, k, A, B, C;
	scanf("%d%d%d", &n, &x, &k);
	map<int, long double> h[2];
	scanf("%d%d%d", &A, &B, &C);
	long double a = A / 100.0, b = B / 100.0, c = C / 100.0;
	int cur = 0, nxt = 1;
	h[cur][x] = 1.0;
	for (int i = 0; i < n; ++i) {
		h[nxt].clear();
		for (auto it = h[cur].begin(); it != h[cur].end(); ++it) {
			int aa = (it->first) & k;
			int bb = (it->first) | k;
			int cc = (it->first) ^ k;
			h[nxt][aa] += (it->second) * a;
			h[nxt][bb] += (it->second) * b;
			h[nxt][cc] += (it->second) * c;
		}
		swap(cur, nxt);
	}
	long double ans = 0.0;
	for (auto it = h[cur].begin(); it != h[cur].end(); ++it)
		ans += (it->first) * (it->second);
	return ans;
}
int main() {
	// freopen("in", "r", stdin);
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case #%d: %.15Lf\n", _, main2());
	return 0;
}
