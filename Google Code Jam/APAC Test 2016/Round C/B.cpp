#include <bits/stdc++.h>

using namespace std;

long double P[105];
long double K[105];
void main2() {
	int N; scanf("%d", &N);
	long double r = 1e200, l = 0;
	for (int i = 0; i < N; ++i) {
		cin >> P[i] >> K[i];
		long double P2 = P[i] + 1;
		if (P2 > 100) P2 = 100;
		P[i] /= 100; P2 /= 100;
		if (P[i] == 0) {
			l = max(l, K[i] / P2);
		} else {
			l = max(l, K[i] / P2);
			r = min(r, K[i] / P[i]);
		}
	}
	if (r - l > 1.0 || r < l) printf("-1\n");
	else printf("%.0Lf\n", r);
}
int main() {
	// freopen("in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		main2();
	}
	return 0;
}
