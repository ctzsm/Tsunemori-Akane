#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

char s[5005];
char b[5] = "bear";
std::vector<int> g;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i <= n - 4; ++i) {
		bool flag = true;
		for (int j = 0; j < 4; ++j) {
			if (s[i + j] != b[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			g.push_back(i);
		}
	}
	int ans = 0;
	for (int i = 0, k = 0; i <= n - 4; ++i) {
		if (k < (int)g.size() && g[k] < i) k++;
		if (k == (int)g.size()) break;
		ans += n - (g[k] + 3);
	}
	printf("%d\n", ans);
	return 0;
}