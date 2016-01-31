#include <bits/stdc++.h>

using namespace std;

int n, q, a[200005];
long long l[200005], r[200005];
long long ll[200005], rr[200005];
pair<bool, pair<long long, int> > check(long long m, long long x) {
	long long res = 0, tot = 0, cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (l[i] - l[i - 1] > m) continue;
		if (l[n] - l[i - 1] <= m) {
			res += n - i + 1;
			if (l[n] - l[i - 1] == m)
				cnt ++, res --;
			tot += ll[n] - ll[i - 1] - (n - i + 1) * l[i - 1];
			continue;
		}
		int L = i, R = n;
		while (L < R) {
			int M = (L + R) >> 1;
			if (l[M] - l[i - 1] >= m) R = M;
			else L = M + 1;
		}
		if (l[L] - l[i - 1] == m) {
			tot += ll[L] - ll[i - 1] - (L - i + 1) * l[i - 1];
			cnt ++;
		} else {
			tot += ll[L - 1] - ll[i - 1] - (L - i) * l[i - 1];
		}
		res += L - i;
	}
	return make_pair(res + cnt >= x, make_pair(tot, res + cnt - x));
}
long long prefix(long long x) {
	if (x == 0) return 0;
	long long L = 0, R = l[n];
	int cnt = 0;
	while (L < R) {
		long long m = (L + R) >> 1;
		pair<bool, pair<long long, int> > r = check(m, x);
		if (r.first)
			R = m;
		else {
			L = m + 1;
		}
	}
	pair<bool, pair<long long, int> > r = check(L, x);
	// printf("-- tot = %lld L = %lld\n", r.second.first, L);
	return r.second.first - r.second.second * L;
}
void main2() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) l[i] = l[i - 1] + a[i];
	for (int i = 1; i <= n; ++i) ll[i] = ll[i - 1] + l[i];
	rr[n + 1] = r[n + 1] = 0;
	for (int i = n; i >= 1; --i) r[i] = r[i + 1] + a[i];
	for (int i = n; i >= 1; --i) rr[i] = rr[i + 1] + r[i];
	while (q--) {
		long long a, b;
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", prefix(b) - prefix(a - 1));
	}
}
int main() {
	// freopen("in", "r", stdin);
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d:\n", _);
		main2();
	}
	return 0;
}
