#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

void solve(int x, bool flag = false) {
	if (x == 0) {
		printf("INSOMNIA\n");
		return;
	}
	int cnt = 0, p = x, n = 0;
	while (true) {
		int y = p;
		while (y) {
			cnt |= 1 << (y % 10);
			y /= 10;
		}
		if (cnt == 1023) break;
		p += x, n ++;
	}
	if (n > 30 && flag) printf("%d\n", p); 
	if (!flag) printf("%d\n", p);
}
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		int n; scanf("%d", &n);
		solve(n);
	}
	return 0;
}
