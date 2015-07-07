#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 101;
int T, n;
int prime[maxn], pcnt, c[maxn];
bool isNotPrime[maxn];
void getPrime() {
	for (int i = 2; i < maxn; ++i)
		if (!isNotPrime[i]) {
			prime[pcnt++] = i;
			for (int j = i + i; j < maxn; j += i)
				isNotPrime[j] = true;
		}
}
int main() {
	freopen("in", "r", stdin);
	getPrime();
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d", &n);
		printf("Case %d: %d =", _, n);
		int cnt = 0;
		memset(c, 0, sizeof c);
		for (int i = 0; i < pcnt && prime[i] <= n; ++i, ++cnt) {
			int x = n;
			while (x) {
				c[i] += x / prime[i];
				x /= prime[i];
			}
		}
		for (int i = 0; i < cnt; ++i) {
			if (i) printf(" *");
			printf(" %d (%d)", prime[i], c[i]);
		}
		printf("\n");
	}
	return 0;
}
