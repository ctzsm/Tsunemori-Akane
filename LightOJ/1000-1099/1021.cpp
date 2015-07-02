#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, n, k;
long long f[1 << 16][20];
char s[20];
bool v[20];
long long solve() {
	scanf("%d%d%s", &n, &k, s);
	memset(v, false, sizeof v);
	for (int i = 0; s[i]; ++i) {
		if (isdigit(s[i])) v[s[i] - '0'] = true;
		else v[s[i] - 'A' + 10] = true;
	}
	int m = 0;
	memset(f, 0, sizeof f);
	for (int i = 0; i < n; ++i) if (v[i])
		m |= 1 << i;
	f[0][0] = 1;
	for (int mask = 0; mask < (1 << n); ++mask) {
		for (int i = 0; i < n; ++i) if (v[i] && (mask & (1 << i)) == 0) {
			for (int j = 0; j < k; ++j)
				f[mask | (1 << i)][(j * n + i) % k] += f[mask][j];
		}
	}
	return f[m][0];
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %lld\n", _, solve());
	return 0;
}
