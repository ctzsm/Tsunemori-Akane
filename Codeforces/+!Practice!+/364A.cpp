#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 4005;
int n, a, pre[maxn], cnt[maxn * 10];
char s[maxn];
int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &a);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
		pre[i] = pre[i - 1] + s[i] - '0';
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			cnt[pre[i] - pre[j]] ++;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			int sum = pre[i] - pre[j];
			if (sum == 0 && a == 0) {
				ans += n * (n + 1) / 2;
			} else if (sum && a % sum == 0 && a / sum <= n * 10) {
				ans += cnt[a / sum];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
