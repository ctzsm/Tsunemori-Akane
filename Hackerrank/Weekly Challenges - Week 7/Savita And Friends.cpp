#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const long long oo = 0x3fffffffffffffffLL;
const double eps = 1e-6;
int N, M, K;
vector<pair<int, long long> > adj[100005];
int Ak, Bk, Ck;
long long dist[100005], dA[100005];
struct ltDist {
	bool operator() (int u, int v) const {
		if (dist[u] == dist[v])
			return u < v;
		return dist[u] < dist[v];
	}
};
void dijkstra(int s) {
	for (int i = 1; i <= N; ++i) dist[i] = oo;
	dist[s] = 0;
	
	set<int, ltDist> q;
	q.insert(s);
	while (!q.empty()) {
		int u = *q.begin();
		q.erase(q.begin());
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].first;
			long long newDist = adj[u][i].second + dist[u];
			if (newDist < dist[v]) {
				if (q.count(v)) q.erase(v);
				dist[v] = newDist;
				q.insert(v);
			}
		}
	}
	// for (int i = 1; i <= N; ++i) printf("%d\t", dist[i]); printf("\n");
}
double calc(double x) {
	double ret = 0.0;
	for (int i = 1; i <= N; ++i)
		ret = max(ret, min(x + dA[i], Ck - x + dist[i]));
	return ret;
}
void solve() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; ++i) adj[i].clear();
	for (int i = 1; i <= M; ++i) {
		int A, B, C; scanf("%d%d%d", &A, &B, &C);
		adj[A].push_back(make_pair(B, C));
		adj[B].push_back(make_pair(A, C));
		if (i == K) Ak = A, Bk = B, Ck = C;
	}
	dijkstra(Ak);
	for (int i = 1; i <= N; ++i) dA[i] = dist[i];
	dijkstra(Bk);
	double l = 0, h = Ck, mid1, mid2, v1, v2;
	while (h - l > eps) {
		mid1 = (l * 2 + h) / 3.0;
		mid2 = (l + h * 2) / 3.0;
		v1 = calc(mid1), v2 = calc(mid2);
		if (v1 > v2) l = mid1;
		else h = mid2;
	}
	if (calc(0) < v1) l = 0, v1 = calc(0);
	if (calc(Ck) < v1) l = Ck, v1 = calc(Ck);
	printf("%.5f %.5f\n", l, v1);
}
int main() {
	freopen("input04.txt", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}