#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int> > PIII;
int T, n;
int f[105];
int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
bool merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) return false;
	f[fy] = fx;
	return true;
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d", &n);
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		vector<PIII> edge;
		vector<bool> flag;
		while (!(u == 0 && v == 0 && w == 0)) {
			edge.push_back(make_pair(w, make_pair(u, v)));
			flag.push_back(false);
			scanf("%d%d%d", &u, &v, &w);
		}
		int ans1 = 0, ans2 = 0;
		sort(edge.begin(), edge.end());
		for (int i = 0; i <= n; ++i) f[i] = i;
		for (int i = 0, j = 0; i < edge.size() && j < n; ++i) {
			if (merge(edge[i].second.first, edge[i].second.second)) {
				ans1 += edge[i].first;
				j ++;
				flag[i] = true;
			}
		}
		for (int i = 0; i < flag.size(); ++i) flag[i] = false;
		reverse(edge.begin(),edge.end());
		for (int i = 0; i <= n; ++i) f[i] = i;
		for (int i = 0, j = 0; i < edge.size() && j < n; ++i) {
			if (merge(edge[i].second.first, edge[i].second.second)) {
				ans2 += edge[i].first;
				j ++;
				flag[i] = true;
			}
		}
		if ((ans1 + ans2) & 1) {
			printf("Case %d: %d/%d\n", _, ans1 + ans2, 2);
		} else {
			printf("Case %d: %d\n", _, (ans1 + ans2) / 2);
		}
	}
	return 0;
}
