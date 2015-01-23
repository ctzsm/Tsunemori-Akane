#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int __, n;
vector<pair<int, int> > d[105];
vector<int> bw;
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &__);
	while (__--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) d[i].clear();
		bw.clear();
		int bmin = 0, bmax = 0x7fffffff;
		for (int i = 0; i < n; ++i) {
			int m; scanf("%d", &m);
			int tmin = 0x7fffffff, tmax = 0;
			for (int j = 0; j < m; ++j) {
				int b, p; scanf("%d%d", &b, &p);
				d[i].push_back(make_pair(b, p));
				tmin = min(tmin, b), tmax = max(tmax, b);
				bw.push_back(b);
			}
			bmin = max(bmin, tmin);
			bmax = min(bmax, tmax);
		}
		sort(bw.begin(), bw.end());
		bw.resize(unique(bw.begin(), bw.end()) - bw.begin());
		double ans = 0.0;
		for (int i = 0; i < (int)bw.size(); ++i) {
			if (bmin <= bw[i] && bw[i] <= bmax) {
				double totp = 0;
				for (int j = 0; j < n; ++j) {
					int price = 0x7fffffff;
					for (int k = 0; k < (int)d[j].size(); ++k) {
						if (d[j][k].first >= bw[i])
							price = min(price, d[j][k].second);
					}
					totp += price;
				}
				ans = max(ans, bw[i] / totp);
			}
		}
		printf("%.3f\n", ans);
	}
	return 0;
}