#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int oo = 0x3f3f3f3f;
struct edge {
	int u, v, w;
	edge(int _u, int _v, int _w):u(_u), v(_v), w(_w) {}
	bool operator < (const edge& x) const {
		return w < x.w;
	}
};
int T, n, m, t;
int w[505], f[505];
int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) return;
	f[fy] = fx;
}
vector<edge> edges;
void solve() {
	scanf("%d%d", &n, &m);
	memset(w, 0x3f, sizeof w);
	edges.clear();
	for (int i = 0; i < m; ++i) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		edges.push_back(edge(u, v, w));
	}
	sort(edges.begin(), edges.end());
	scanf("%d", &t); w[t] = 0;
	for (int i = 0; i < n; ++i) f[i] = i;
	for (int i = 0; i < m; ++i) {
		merge(edges[i].u, edges[i].v);
		for (int j = 0; j < n; ++j) {
			if (w[j] > edges[i].w && find(t) == find(j)) {
				w[j] = edges[i].w;
			}
		}
	}
	for (int i = 0; i < n; ++i)
		if (w[i] == oo)
			printf("Impossible\n");
		else
			printf("%d\n", w[i]);
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		solve();
	}
	return 0;
}
