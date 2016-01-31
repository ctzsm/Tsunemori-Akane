#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[4][1005];
long long main2() {
	scanf("%d%d", &n, &k);
	map<int, int> h;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			h[a[0][i] ^ a[1][j]] ++;
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x = a[2][i] ^ a[3][j];
			int y = x ^ k;
			if (h.find(y) != h.end())
				ans += h[y];
		}
	}
	return ans;
}
int main() {
	// freopen("in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case #%d: %lld\n", _, main2());
	return 0;
}
