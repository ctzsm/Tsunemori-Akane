#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

inline int lowbit(int x) { return x & -x; }
int N, n, m, C[200005];
pair<pair<int, int>, int> P[200005];
void update(int x) {
	while (x <= N) {
		C[x] += 1;
		x += lowbit(x);
	}
}
int query(int x) {
	int res = 0;
	while (x) {
		res += C[x];
		x -= lowbit(x);
	}
	return res;
}
long long solve() {
	scanf("%d%d", &n, &m);
	N = n + m;
	memset(C, 0, (N + 1) * sizeof(int));
	for (int i = 0; i < n; ++i) {
		int p, q; scanf("%d%d", &p, &q);
		P[i] = make_pair(make_pair(p, q), 0);
	}
	for (int i = 0; i < m; ++i) {
		int p, q; scanf("%d%d", &p, &q);
		P[i + n] = make_pair(make_pair(p, q), 1);
	}
	sort(P, P + N);
	long long res = 0, cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (P[i].second == 0) {
			update(P[i].first.second);
			cnt ++;
		} else {
			res += cnt - query(P[i].first.second - 1);
		}
	}
	memset(C, 0, (N + 1) * sizeof(int));
	for (int i = N - 1; i > -1; --i) {
		if (P[i].second == 0) {
			update(P[i].first.second);
		} else {
			res += query(P[i].first.second);
		}
	}
	return res;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %lld\n", _, solve());
	return 0;
}
