#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

int N, M;
class edges {
public:
	int u, v, w, c;
	edges() {}
	void read() {
		scanf("%d%d%d", &u, &v, &w);
		c = 1;
	}
	bool operator < (const edges &x) const {
		return w < x.w;
	}
} edge[105];
int f[105], visit[105], U[105];
long long G[105][105], C[105][105];
std::vector<int> V[105];
int find(int x, int f[]) {
	if (x == f[x]) return x;
	return f[x] = find(f[x], f);
}
long long det(long long a[][105], int n) {
	long long ret = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = i + 1; j < n; ++j)
			while (a[j][i]) {
				long long t = a[i][i] / a[j][i];
				for (int k = i; k < n; ++k)
					a[i][k] -= a[j][k] * t;
				for (int k = i; k < n; ++k)
					std::swap(a[i][k], a[j][k]);
				ret = -ret;
			}
		if (a[i][i] == 0)
			return 0;
		ret *= a[i][i];
	}
	return ret;
}
void solve() {
	long long ans1 = 1, ans2 = 1;
	for (int i = 0; i < M; ++i) {
		int u = edge[i].u, v = edge[i].v;
		G[u][v] = (G[v][u] -= 1);
		G[u][u] ++;
		G[v][v] ++;
	}
	ans2 = det(G, N);
	memset(G, 0, sizeof G);
	memset(C, -1, sizeof C);
	for (int i = 0; i < M; ++i) {
		int u = edge[i].u, v = edge[i].v;
		if (C[u][v] == -1 || C[u][v] > edge[i].w) {
			G[u][v] = G[v][u] = 1;
			C[u][v] = C[v][u] = edge[i].w;
		} else if (C[u][v] == edge[i].w) {
			G[u][v] ++, G[v][u] ++;
		}
	}
	M = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			if (G[i][j]) {
				edge[M].u = i, edge[M].v = j, edge[M].c = G[i][j], edge[M].w = C[i][j];
				M ++;
			}
		}
	}
	std::sort(edge, edge + M);
	memset(G, 0, sizeof G);
	memset(C, 0, sizeof C);
	for (int i = 1; i <= N; ++i)
		f[i] = i, visit[i] = 0;
	int Edge = -1;
	for (int k = 0; k <= M; ++k) {
		if (edge[k].w != Edge || k == M) {
			for (int i = 1; i <= N; ++i) {
				if (visit[i]) {
					int u = find(i, U);
					V[u].push_back(i);
					visit[i] = 0;
				}
			}
			for (int i = 1; i <= N; ++i) {
				if (V[i].size() > 1) {
					memset(C, 0, sizeof C);
					int len = V[i].size();
					for (int a = 0; a < len; ++a)
						for (int b = a + 1; b < len; ++b) {
							int a1 = V[i][a], b1 = V[i][b];
							C[a][b] = (C[b][a] -= G[a1][b1]);
							C[a][a] += G[a1][b1];
							C[b][b] += G[a1][b1];
						}
					long long ret = det(C, len);
					ans1 *= ret;
					for (int a = 0; a < len; a++)
						f[V[i][a]] = i;
				}
			}
			for (int i = 1; i <= N; i++) {
				U[i] = f[i] = find(i, f);
				V[i].clear();
			}
			if (k == M)
				break;
			Edge = edge[k].w;
		}

		int a = edge[k].u;
		int b = edge[k].v;
		int a1 = find(a, f);
		int b1 = find(b, f);
		if (a1 == b1)
			continue;
		visit[a1] = visit[b1] = 1;
		U[find(a1, U)] = find(b1, U);
		G[a1][b1] += edge[k].c;
		G[b1][a1] += edge[k].c;
	}
	long long gcd = std::__gcd(ans1, ans2);
	ans1 /= gcd;
	ans2 /= gcd;

	printf("%lld/%lld\n", ans1, ans2);
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i)
		edge[i].read();
	solve();
	return 0;
}