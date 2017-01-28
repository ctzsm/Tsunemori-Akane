#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100000;
bool is_not_prime[maxn + 5];
int primes[maxn / 2], f[maxn + 5], pcnt = 0;
int n, used[maxn + 5];
void get_primes() {
	for (int i = 2; i <= maxn; ++i) {
		if (!is_not_prime[i]) {
			primes[pcnt++] = i;
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
int dfs(vector<pair<int, int> >& u, int i, int x, int id, int y) {
	int res = 0;
	if (i == u.size()) {
		if (y == 0 || used[x] < id - y)
			res = 1;
		used[x] = max(used[x], id);
		return res;
	}
	int t = 1;
	for (int j = 0; j <= u[i].second; ++j) {
		res += dfs(u, i + 1, x * t, id, y);
		t *= u[i].first;
	}
	return res;
}
int main() {
	// freopen("in", "r", stdin);
	get_primes();
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		vector<int> v;
		vector<pair<int, int> > u;
		while (x > 1) {
			v.push_back(f[x]);
			x /= f[x];
		}
		if (v.size() == 0) {
			printf("0\n");
			continue;
		}
		sort(v.begin(), v.end());
		int cnt = 1, now = v[0];
		for (int j = 1; j < v.size(); ++j) {
			if (now != v[j]) {
				u.push_back(make_pair(now, cnt));
				now = v[j], cnt = 1;
			} else {
				cnt ++;
			}
		}
		u.push_back(make_pair(now, cnt));
		printf("%d\n", dfs(u, 0, 1, i, y));
	}
	return 0;
}
