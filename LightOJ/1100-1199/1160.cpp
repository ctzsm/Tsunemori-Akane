#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxs = 36;
const int maxn = 840;
const long long mod = 1000000007;
struct matrix {
	long long a[maxs][maxs];
	void print() {
		for (int i = 0; i < maxs; ++i) {
			for (int j = 0; j < maxs; ++j) printf("%lld ", a[i][j]);
			printf("\n");
		}
	}
	matrix operator * (const matrix& y) {
		matrix res; memset(res.a, 0, sizeof res.a);
		for (int i = 0; i < maxs; ++i)
			for (int j = 0; j < maxs; ++j)
				for (int k = 0; k < maxs; ++k) {
					res.a[i][j] = res.a[i][j] + a[i][k] * y.a[k][j];
					if (res.a[i][j] >= mod) res.a[i][j] %= mod;
				}
		return res;
	}
	matrix pow(int k) {
		matrix res, p;
		memset(res.a, 0, sizeof res.a);
		memcpy(p.a, a, sizeof p.a);
		for (int i = 0; i < maxs; ++i) res.a[i][i] = 1;
		while (k) {
			if (k & 1) res = res * p;
			p = p * p;
			k >>= 1;
		}
		return res;
	}
};
vector<int> h[maxn], clique[maxn], adj[maxn];
bool e[maxn][maxn];
int tag[maxn];
void bfs(int x, int t) {
	queue<int> q; q.push(x); tag[x] = t;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i];
			if (tag[v] != -1) continue;
			tag[v] = t;
			q.push(v);
		}
	}
}
void init() {
	vector<int> v;
	for (int i = 0; i < 7; ++i) v.push_back(max(0, i - 2));
	int cnt = 0;
	do {
		h[cnt++] = v;
	} while (next_permutation(v.begin(), v.end()));
	for (int i = 0; i < maxn; ++i) {
		for (int j = 0; j < maxn; ++j) {
			if (i == j) continue;
			bool flag = true;
			for (int k = 0; k < 7; ++k) {
				if (h[i][k] == 0) continue;
				bool check = false;
				for (int l = -1; l < 2; l += 2) {
					int nk = l + k;
					if (nk < 0 || nk >= 7) continue;
					if (h[j][nk] == h[i][k]) check = true;
				}
				flag = flag && check;
				if (!flag) break;
			}
			if (flag) {
				adj[i].push_back(j);
				e[i][j] = true;
			}
		}
	}
	cnt = 0; memset(tag, -1, sizeof tag);
	for (int i = 0; i < maxn; ++i)
		if (tag[i] == -1)
			bfs(i, cnt++);
	for (int i = 0; i < maxn; ++i)
		clique[tag[i]].push_back(i);
}
long long solve() {
	int N; scanf("%d", &N);
	vector<int> v;
	for (int i = 0; i < 7; ++i) {
		int x; scanf("%d", &x);
		v.push_back(x);
	}
	int id = lower_bound(h, h + maxn, v) - h;
	int t = tag[id];
	matrix o, a;
	memset(a.a, 0, sizeof a.a);
	memset(o.a, 0, sizeof o.a);
	for (int i = 0; i < clique[t].size(); ++i) {
		int u = clique[t][i];
		if (u == id) a.a[0][i] = 1;
		for (int j = 0; j < clique[t].size(); ++j) {
			int v = clique[t][j];
			o.a[i][j] = e[u][v];
		}
	}
	matrix res = a * o.pow(N - 1);
	long long ans = 0;
	for (int i = 0; i < maxs; ++i) ans += res.a[0][i];
	return ans % mod;
}
int main() {
	freopen("in", "r", stdin);
	init();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %lld\n", _, solve());
	return 0;
}
