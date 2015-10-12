#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const long long mod = 1000000007;
int N, M, K;
int modPow(int x, int k, int m) {
	long long res = 1, p = x % m;
	while (k) {
		if (k & 1) res = res * p % m;
		p = p * p % m;
		k >>= 1;
	}
	return res;
}
long long a[105][105];
int lb[105], choose[105];
int Guass() {
	memset(lb, 0, sizeof lb);
	memset(choose, 0, sizeof choose);
	for (int i = 1; i <= N; ++i) {
		int& l = lb[i];
		for (int j = 1; j <= N; ++j)
			if (!choose[j] && a[j][i]) {
				choose[j] = 1, l = j;
				break;
			}
		if (!l) continue;
		long long inv = modPow(a[l][i], K - 2, K);
		for (int j = i; j <= N; ++j)
			a[l][j] = a[l][j] * inv % K;
		for (int j = 1; j <= N; ++j) {
			if (j == l) continue;
			if (!a[j][i]) continue;
			long long m = a[j][i];
			for (int k = i; k <= N; ++k) {
				a[j][k] -= a[l][k] * m % K;
				if (a[j][k] < 0) a[j][k] += K;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= N; ++i)
		if (!lb[i]) res ++;
	return res;
}
int solve() {
	scanf("%d%d%d", &N, &M, &K);
	memset(a, 0, sizeof a);
	for (int i = 0; i < M; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		a[u][v] = a[v][u] = 1;
	}
	for (int i = 1; i <= N; ++i)
		a[i][i] = K - 1;
	int f = Guass();
	return modPow(K, f, mod);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
