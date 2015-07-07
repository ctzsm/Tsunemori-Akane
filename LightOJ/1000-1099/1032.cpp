#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, n;
long long f[30];
long long calc(int c) {
	long long res = 0, x = c;
	for (int i = 30; i >= 0; --i) {
		if (c & (1 << i)) {
			x -= 1 << i;
			if (i)
				res += f[i - 1];
			if (i < 30 && (c & (1 << (i + 1))))
				res += x + 1;
		}
	}
	return res;
}
int main() {
	freopen("in", "r", stdin);
	for (int i = 1; i < 31; ++i) f[i] = f[i - 1] * 2 + (1 << (i - 1));
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d", &n);
		printf("Case %d: %lld\n", _, calc(n));
	}
	return 0;
}
