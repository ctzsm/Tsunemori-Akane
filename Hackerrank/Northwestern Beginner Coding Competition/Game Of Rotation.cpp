#include <bits/stdc++.h>

using namespace std;

int N;
long long a[1000006], s[1000006];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%lld", &a[i]);
	for (int i = 1; i <= N; ++i) s[i] = a[i] + s[i - 1];
	long long ans = 0;
	for (int i = 1; i <= N; ++i) ans += a[i] * i;
	long long sum = ans;
	for (int i = 1; i <= N; ++i) {
		sum = sum - s[N] + a[i] * N;
		ans = max(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}