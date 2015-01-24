#include <bits/stdc++.h>

using namespace std;

int N, K, a[100005];
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
	sort(a, a + N);
	int ans = a[K - 1] - a[0];
	for (int i = K; i < N; ++i) 
		ans = min(ans, a[i] - a[i - K + 1]);
	printf("%d\n", ans);
	return 0;
}