#include <bits/stdc++.h>

using namespace std;

int a[1005];
void main2() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	while (m --) {
		int L, R; scanf("%d%d", &L, &R);
		int D = R - L + 1;
		double V = 0;
		for (int i = L; i <= R; ++i)
			V += log(a[i]);
		printf("%.10f\n", exp(V / D));
	}
}
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d:\n", _);
		main2();
	}
	return 0;
}
