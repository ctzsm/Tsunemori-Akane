#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	int top; scanf("%d", &top);
	int bot = 7 - top;
	for (int i = 0; i < n; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		int opl = 7 - l, opr = 7 - r;
		if (i == 0) continue;
		bool f[7]; memset(f, false, sizeof(f));
		f[l] = f[r] = f[opl] = f[opr] = f[bot] = true;
		int cnt = 0;
		for (int j = 1; j <= 6; ++j)
			cnt += f[j];
		cnt = 6 - cnt;
		if (cnt > 1) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}