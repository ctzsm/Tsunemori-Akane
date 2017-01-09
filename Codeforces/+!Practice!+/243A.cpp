#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005, maxm = 1 << 20, maxk = 20;
int n, a[maxn];
bool ans[maxm];
set<int> ind[maxk];
int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		for (int j = 0; j < maxk; ++j) {
			if (a[i] & (1 << j)) {
				ind[j].insert(i);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < maxk; ++j) {
			if (a[i] & (1 << j)) {
				ind[j].erase(i);
			}
		}
		vector<pair<int, int> > v;
		for (int j = 0; j < maxk; ++j) {
			if (ind[j].size() > 0) {
				v.push_back(make_pair(*ind[j].begin(), j));
			}
		}
		sort(v.begin(), v.end());
		int k = 0, now = a[i];
		for (int j = 0; j < v.size(); ++j) {
			if (k != v[j].first) {
				ans[now] = true, k = v[j].first;
			}
			now |= 1 << v[j].second;
		}
		ans[now] = true;
	}
	int cnt = 0;
	for (int i = 0; i < maxm; ++i)
		cnt += ans[i];
	printf("%d\n", cnt);
	return 0;
}
