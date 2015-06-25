#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int T;
long long n;
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%lld", &n);
		long long sn = (long long)(sqrt(n - 1) + 1e-5);
		long long re = n - sn * sn;
		int col = 0, row = 0;
		if (sn & 1) {
			if (re <= sn) {
				col = re;
				row = sn + 1;
			} else {
				col = sn + 1;
				row = sn * 2 + 2 - re;
			}
		} else {
			if (re <= sn) {
				col = sn + 1;
				row = re;
			} else {
				col = sn * 2 + 2 - re;
				row = sn + 1;
			}
		}
		printf("Case %d: %d %d\n", _, col, row);
	}
	return 0;
}
