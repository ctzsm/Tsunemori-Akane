#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long f[20][10]; // length, leading digit
char s[50];
long long g(int l, int d) {
	if (l < 1) return 0;
	if (l < 3) return 1;
	if (~f[l][d]) return f[l][d];
	long long res = 0;
	for (int i = 0; i < 10; ++i)
		res += g(l - 2, i);
	return f[l][d] = res;
}
long long calc(long long x) {
	if (x < 0) return 0;
	if (x < 10) return x + 1;
	sprintf(s, "%lld", x);
	int n = strlen(s);
	long long ans = 1;
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < 10; ++j)
			ans += g(i, j);
	for (int i = 0; i <= n / 2; ++i) {
		int d = s[i] - '0';
		for (int j = i == 0; j < d; ++j)
			ans += g(n - i * 2, j);
	}
	bool ok = true;
	for (int i = n / 2 - 1 + (n & 1), j = n / 2; i >= 0; --i, ++j)
		if (s[i] > s[j]) ok = false;
		else if (s[i] < s[j]) break;
	ans += ok;
	return ans;
}
bool check(int x) {
	sprintf(s, "%d", x);
	int l = strlen(s);
	for (int i = 0, j = l - 1; i < j; ++i, --j) if (s[i] != s[j]) return false;
	return true;
}
long long solve() {
	long long i, j;
	scanf("%lld%lld", &i, &j);
	if (i > j) swap(i, j);
	return calc(j) - calc(i - 1);
}
int main() {
	freopen("in", "r", stdin);
	memset(f, -1, sizeof f);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %lld\n", _, solve());
	return 0;
}
