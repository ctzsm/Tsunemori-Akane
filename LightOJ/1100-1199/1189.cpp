#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

map<long long, int> h;
long long f[20] = {1};
long long x[10005];
void init() {
	for (int i = 1; i < 20; ++i) f[i] = f[i - 1] * i;
	int l = 1 << 20;
	for (int i = 1; i < l; ++i) {
		long long x = 0;
		for (int j = 0; j < 20; ++j) {
			if (i & (1 << j))
				x += f[j];
		}
		if (h.find(x) == h.end()) continue;
		h[x] = i;
	}
}
void print(long long x) {
	int mask = h[x];
	if (mask == -1) {
		printf("impossible\n");
		return;
	}
	for (int i = 0, f = 0; i < 20; ++i) {
		if (mask & (1 << i)) {
			if (f) putchar('+');
			f = 1;
			printf("%d!", i);
		}
	} 
	putchar('\n');
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%lld", &x[_]);
		h[x[_]] = -1;
	}
	init();
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		print(x[_]);
	}
	return 0;
}
