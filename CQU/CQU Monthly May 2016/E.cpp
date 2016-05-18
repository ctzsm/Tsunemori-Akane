#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int T, n;
int primes[maxn + 5], pcnt = 0;
int f[maxn + 5], g[maxn + 5];
bool is_not_prime[maxn + 5];
void get_prime() {
	for (int i = 2; i <= maxn; ++i) {
		if (!is_not_prime[i]) {
			primes[pcnt ++] = i;
			f[i] = i;
		}
		for (int j = 0; j < pcnt; ++j) {
			int x = i * primes[j];
			if (x > maxn) break;
			is_not_prime[x] = true;
			f[x] = primes[j];
			if (i % primes[j] == 0) break;
		}
	}
}
int main() {
	freopen("in", "r", stdin);
	get_prime();
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		memset(g, 0, sizeof g);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int x; scanf("%d", &x);
			vector<int> v;
			while (x > 1) {
				int p = f[x];
				v.push_back(p);
				while (x % p == 0) x /= p;
			}
			int l = 0;
			for (int j = 0; j < v.size(); ++j) l = max(l, g[v[j]]);
			for (int j = 0; j < v.size(); ++j) g[v[j]] = max(g[v[j]], l + 1);
			for (int j = 0; j < v.size(); ++j) ans = max(ans, g[v[j]]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
