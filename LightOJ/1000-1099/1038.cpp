#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 100001;
double f[maxn];
int T, n;
int c[maxn], prime[maxn], p;
bool isNotPrime[maxn];
void init() {
	for (int i = 2; i < maxn; ++i)
		if (!isNotPrime[i]) {
			prime[p++] = i;
			for (int j = i + i; j < maxn; j += i)
				isNotPrime[j] = true;
		}
	c[1] = 1;
	for (int i = 2; i < maxn; ++i) {
		if (!isNotPrime[i])
			c[i] = 2;
		else {
			c[i] = 1;
			int x = i, sx = (int)(sqrt(i) + 1.1);
			for (int j = 0; j < p && prime[j] < sx && x > 1; ++j) {
				int cnt = 1;
				while (x % prime[j] == 0) {
					x /= prime[j];
					cnt ++;
				}
				if (cnt > 1) {
					sx = (int)(sqrt(x) + 1.1);
					c[i] *= cnt;
				}
			}
			if (x > 1) c[i] *= 2;
		}
	}
	for (int i = 2; i < maxn; ++i) {
		f[i] += 1.0 / (c[i] - 1) + (f[i] + 1) / (c[i] - 1);
		for (int j = 2; j * i < maxn; ++j) {
			f[i * j] += (f[i] + 1) / c[i * j];
		}
	}
}
int main() {
	freopen("in", "r", stdin);
	init();
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d", &n);
		printf("Case %d: %.8f\n", _, f[n]);
	}
	return 0;
}
