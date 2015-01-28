#include <cstdio>
#include <algorithm>

using namespace std;

struct show {
	int s, e;
	bool operator < (const show &x) const {
		if (e == x.e) return s < x.s;
		return e < x.e;
	}
	void read() {
		scanf("%d%d", &s, &e);
	}
} s[105];
int n;
int main() {
	freopen("in", "r", stdin);
	while (~scanf("%d", &n)) {
		if (n == 0) break;
		for (int i = 0; i < n; ++i) s[i].read();
		sort(s, s + n);
		int ans = 0, now = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i].s < now) continue;
			ans ++, now = s[i].e;
		}
		printf("%d\n", ans);
	}
	return 0;
}