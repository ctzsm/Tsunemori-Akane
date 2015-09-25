#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n, s[3], t[3], ss[3], tt[3];
		scanf("%d", &n);
		for (int i = 0; i < 3; ++i) scanf("%d", s + i);
		for (int i = 0; i < 3; ++i) scanf("%d", t + i);
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < 3; ++j) scanf("%d", ss + j);
			for (int j = 0; j < 3; ++j) scanf("%d", tt + j);
			for (int j = 0; j < 3; ++j) s[j] = max(s[j], ss[j]);
			for (int j = 0; j < 3; ++j) t[j] = min(t[j], tt[j]);
		}
		int ans = 1;
		for (int i = 0; i < 3; ++i) {
			if (t[i] - s[i] > 0) ans *= t[i] - s[i];
			else ans = 0;
		}
		printf("Case %d: %d\n", _, ans);
	}
	return 0;
}
