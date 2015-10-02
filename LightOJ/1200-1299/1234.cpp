#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

pair<int, int> n[10005];
double ans[10005];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int x; scanf("%d", &x);
		n[_] = make_pair(x, _);
	}
	sort(n + 1, n + T + 1);
	double res = 0;
	for (int i = 1, j = 1; j <= T; ++j) {
		while (i <= n[j].first) {
			res += 1.0 / i;
			i ++;
		}
		ans[n[j].second] = res;
	}
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %.10f\n", _, ans[_]);
	return 0;
}
