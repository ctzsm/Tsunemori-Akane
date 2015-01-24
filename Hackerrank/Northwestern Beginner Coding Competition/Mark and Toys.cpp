#include <bits/stdc++.h>

using namespace std;

int N, K, p[100005];
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) scanf("%d", &p[i]);
	sort(p, p + N);
	int ans = 0, sum = 0;
	for (int i = 0; i < N; ++i) {
		if (sum + p[i] > K) break;
		sum += p[i], ans ++;
	}
	printf("%d\n", ans);
	return 0;
}