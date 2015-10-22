#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10000000;
bool check[maxn + 5];
int prime[maxn / 10], pcnt = 0;
void getPrime() {
	for (int i = 2; i <= maxn; ++i) {
		if (!check[i]) prime[pcnt++] = i;
		for (int j = 0; j < pcnt; ++j) {
			if (i * prime[j] > maxn) break;
			check[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
	prime[pcnt++] = maxn;
}
int solve() {
	int n, ans = 0; scanf("%d", &n);
	int l = n / 2;
	for (int i = 0; prime[i] <= l; ++i) {
		if (!check[n - prime[i]]) ans ++;
	}
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	getPrime();
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
