#include <cassert>
#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int S[4][4] = {
	{1, 1, 1, 1},
	{1, -1, 1, -1},
	{1, -1, -1, 1},
	{1, 1, -1, -1}
};
const int Y[4][4] = {
	{0, 1, 2, 3},
	{1, 0, 3, 2},
	{2, 3, 0, 1},
	{3, 2, 1, 0}
};
struct Q {
	int sign, n;
	Q() {}
	Q(int _s, int _n): sign(_s), n(_n) {
		assert(sign == -1 || sign == 1);
		assert(0 <= n && n < 4);
	}
	bool operator != (const Q& q) {
		return sign != q.sign || n != q.n;
	}
	bool operator == (const Q& q) {
		return sign == q.sign && n == q.n;
	}
} pre[10005], suf[10005];
Q multiply(const Q& p, const Q& q) {
	Q res(p.sign * q.sign * S[p.n][q.n], Y[p.n][q.n]);
	return res;
}
Q pow(Q p, long long k) {
	Q res(1, 0);
	while (k) {
		if (k & 1) res = multiply(res, p);
		p = multiply(p, p);
		k >>= 1;
	}
	return res;
}
Q I(1, 1), K(1, 3);
int T;
long long L, X;
char s[10005];
void solve() {
	scanf("%lld%lld%s", &L, &X, s);
	// small
	// for (int j = 1; j < X; ++j)
	// 	for (int i = 0; i < L; ++i)
	// 		s[j * L + i] = s[i];
	// L = L * X;
	// int pl = -1, sl = -1;

	pre[0] = Q(1, s[0] - 'i' + 1);
	suf[L - 1] = Q(1, s[L - 1] - 'i' + 1);
	for (int i = 1; i < L; ++i)
		pre[i] = multiply(pre[i - 1], Q(1, s[i] - 'i' + 1));
	for (int i = L - 2; i >= 0; --i)
		suf[i] = multiply(Q(1, s[i] - 'i' + 1), suf[i + 1]);

	// for (int i = 0; i < L; ++i)
	// 	if (pre[i] == I) {
	// 		pl = i + 1;
	// 		break;
	// 	}
	// for (int i = L - 1; i >= 0; --i)
	// 	if (suf[i] == K) {
	// 		sl = L - i;
	// 		break;
	// 	}
	// if (pl == -1 || sl == -1 || pre[L - 1] != Q(-1, 0) || pl + sl >= L) {
	// 	printf("NO\n");
	// } else {
	// 	printf("\n%d %d\n", pl, sl);
	// 	printf("YES\n");
	// }
	// return;

	if (pow(pre[L - 1], X) != Q(-1, 0)) {
		printf("NO\n");
		return;
	}
	Q w[4] = {Q(1, 0)};
	for (int i = 1; i < 4; ++i) w[i] = multiply(w[i - 1], pre[L - 1]);
	// find i
	long long is = -1, il = -1;
	for (int i = 0; i < 4; ++i) {
		if (w[i] == I) {
			is = i, il = 0;
			break;
		}
		for (int j = 0; j < L; ++j)
			if (multiply(w[i], pre[j]) == I) {
				is = i, il = j + 1;
				break;
			}
		if (is != -1) break;
	}
	// find k
	long long ks = -1, kl = -1;
	for (int i = 0; i < 4; ++i) {
		if (w[i] == K) {
			ks = i, kl = 0;
			break;
		}
		for (int j = L - 1; j >= 0; --j)
			if (multiply(suf[j], w[i]) == K) {
				ks = i, kl = L - j;
				break;
			}
		if (ks != -1) break;
	}
	if (is == -1 || ks == -1 || (is + ks) * L + il + kl >= X * L) {
		printf("NO\n");
		return;
	}
	// printf("\n%lld %lld\n", is * L + il, ks * L + kl);
	printf("YES\n");
}
int main() {
	// freopen("in", "r", stdin);
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}