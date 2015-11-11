#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 355;
const int oo = 0x3f3f3f3f;
struct edge {
	int u, v, c;
	void scan() { scanf("%d%d%d", &u, &v, &c); }
	bool operator < (const edge& x) const { return c < x.c; }
}e[maxn * 200];
bool visited[maxn];
int n, m, f[maxn], q[maxn], h[maxn], b[maxn][maxn], ecnt;
inline void add(int idx) {
	int u = e[idx].u, v = e[idx].v;
	if (f[u] == -1) { f[u] = v; return; }
	if (f[v] == -1) { f[v] = u; return; }
	int p = 0;
	while (u != -1) {
		q[p++] = u;
		u = f[u];
	}
	for (int i = p - 1; i > 0; --i)
		f[q[i]] = q[i - 1];
	f[e[idx].u] = v;
}
int findMin() {
	int res = oo;
	for (int i = 0; i < n; ++i) if (~f[i])
		res = min(res, b[f[i]][i]);
	return res;
}
int treeCycle(int idx) {
	int u = e[idx].u, v = e[idx].v;
	memset(visited, false, n * sizeof(bool));
	int tu = u, tv = v, lca = -1, minc = oo, mv = -1;;
	while (~tu) {
		visited[tu] = true;
		tu = f[tu];
	}
	while (~tv) {
		if (visited[tv]) {
			lca = tv;
			break;
		}
		if (f[tv] == -1) break;
		if (minc > b[f[tv]][tv])
			minc = b[f[tv]][tv], mv = tv;
		tv = f[tv];
	}
	if (lca == -1) {
		add(idx);
		ecnt ++;
		return ecnt == n - 1 ? findMin() : -oo;
	}
	tu = u, tv = v;
	while (tu != lca && ~f[tu]) {
		if (minc > b[f[tu]][tu])
			minc = b[f[tu]][tu], mv = tu;
		tu = f[tu];
	}
	f[mv] = -1;
	add(idx);
	return ecnt == n - 1 ? findMin() : -oo;
}
int main() {
	freopen("G.in", "r", stdin);
	freopen("M.out", "w", stdout);
	while (~scanf("%d", &n)) {
		if (n == 0) break;
		scanf("%d", &m);
		for (int i = 0; i < m; ++i) {
			e[i].scan();
			b[e[i].u][e[i].v] = b[e[i].v][e[i].u] = e[i].c;
		}
		sort(e, e + m);
		memset(f, -1, sizeof f);
		int ans = oo; ecnt = 0;
		for (int i = 0; i < m; ++i) {
			int minc = treeCycle(i);
			ans = min(ans, e[i].c - minc);
		}
		printf("%d\n", ans);
	}
	return 0;
}
