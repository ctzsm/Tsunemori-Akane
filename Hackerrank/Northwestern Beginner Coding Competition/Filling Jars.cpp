#include <bits/stdc++.h>

using namespace std;

int N, M;
long long sum = 0;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int a, b, k; scanf("%d%d%d", &a, &b, &k);
		sum += 1LL * k * (b - a + 1);
	}
	printf("%lld\n", sum / N);
	return 0;
}