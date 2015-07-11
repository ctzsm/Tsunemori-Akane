#include <map>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int T, n, m;
int f[105];
typedef pair<int, pair<int, int> > PIII;
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
void solve() {
	n = 0;
	scanf("%d", &m);
	vector<PIII> e;
	map<string, int> h;
	for (int i = 0; i < m; ++i) {
		string s, t; int v;
		cin >> s >> t >> v;
		if (h.find(s) == h.end())
			h[s] = n++;
		if (h.find(t) == h.end())
			h[t] = n++;
		e.push_back(make_pair(v, make_pair(h[s], h[t])));
	}
	for (int i = 0; i < n; ++i) f[i] = i;
	sort(e.begin(), e.end());
	int j = 0, mst = 0;
	for (int i = 0; i < e.size(); ++i) {
		if (merge(e[i].second.first, e[i].second.second)) {
			mst += e[i].first;
			j ++;
			if (j == n - 1) break;
		}
	}
	if (j != n - 1)
		printf("Impossible\n");
	else
		printf("%d\n", mst);
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		solve();
	}
	return 0;
}
