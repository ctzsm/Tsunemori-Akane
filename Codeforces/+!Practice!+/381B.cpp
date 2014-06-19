#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int m, c[5005];
std::vector<int> ans;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int a; scanf("%d", &a);
		c[a] ++;
	}
	for (int i = 1; i <= 5000; ++i) {
		if (c[i]) {
			ans.push_back(i);
			c[i] --;
		}
	}
	for (int i = ans[ans.size() - 1] - 1; i > 0; --i) {
		if (c[i]) {
			ans.push_back(i);
		}
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) printf("%d ", ans[i]);
	return 0;
}