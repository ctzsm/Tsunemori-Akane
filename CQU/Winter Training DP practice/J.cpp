#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

int n, f[185], nCase = 1;
vector<int> block[185];
int main() {
	freopen("in", "r", stdin);
	while (scanf("%d", &n), n) {
		int m = 0;
		for (int i = 0; i < n; ++i) {
			vector<int> v;
			for (int j = 0; j < 3; ++j) {
				int x; scanf("%d", &x);
				v.push_back(x);
			}
			sort(v.begin(), v.end());
			do {
				block[m].clear();
				for (int j = 0; j < 3; ++j) block[m].push_back(v[j]);
				m++;
			} while (next_permutation(v.begin(), v.end()));
		}
		sort(block, block + m, greater<vector<int> >());
		memset(f, 0, sizeof f);
		int ans = 0;
		for (int i = 0; i < m; ++i) {
			f[i] = block[i][2];
			for (int j = 0; j < i; ++j) {
				if (block[j][0] > block[i][0] && block[j][1] > block[i][1])
					f[i] = max(f[i], f[j] + block[i][2]);
			}
			ans = max(ans, f[i]);
		}
		printf("Case %d: maximum height = %d\n", nCase++, ans);
	}
	return 0;
}