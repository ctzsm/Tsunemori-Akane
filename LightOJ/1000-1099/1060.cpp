#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T;
long long K, f[22] = {1};
char s[22];
int cnt[26];
void solve() {
	scanf("%s%lld", s, &K);
	int n = strlen(s);
	sort(s, s + n);
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < n; ++i) cnt[s[i] - 'a'] ++;
	long long t = f[n];
	for (int i = 0; i < 26; ++i)
		t /= f[cnt[i]];
	if (t < K) {
		printf("Impossible\n");
		return;
	}
	K --;
	for (int i = 0; i < n; ++i) {
		long long pre = 0;
		for (int j = 0; j < 26; ++j) {
			if (!cnt[j]) continue;
			long long t = f[n - i - 1];
			for (int k = 0; k < 26; ++k) {
				if (!cnt[k]) continue;
				if (k == j) t /= f[cnt[k] - 1];
				else t /= f[cnt[k]];
			}
			if (K < t + pre) {
				K -= pre;
				putchar('a' + j);
				cnt[j] --;
				break;
			}
			pre += t;
		}
	}
	putchar('\n');
}
int main() {
	for (int i = 1; i < 22; ++i) f[i] = f[i - 1] * i;
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		solve();
	}
	return 0;
}
