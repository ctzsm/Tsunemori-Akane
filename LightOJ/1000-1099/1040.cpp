#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int T, n;
int f[55];
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
int solve() {
	scanf("%d", &n);
	int sum = 0;
	vector<PIII> e;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x; scanf("%d", &x);
			sum += x;
			if (i == j || x == 0) continue;
			e.push_back(make_pair(x, make_pair(i, j)));
		}
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
	if (j != n - 1) return -1;
	return sum - mst;
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
