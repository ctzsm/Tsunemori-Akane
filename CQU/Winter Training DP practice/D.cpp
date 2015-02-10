#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

int T, N, a[100005];
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
		printf("Case %d:\n", _);
		int sum = a[0], t = 0, l = 0, r = 0;
		for (int i = 1; i < N; ++i) {
			if (a[i - 1] < 0)
				t = i;
			else a[i] += a[i - 1];
			if (sum < a[i])
				sum = a[i], l = t, r = i;
		}
		printf("%d %d %d\n", sum, l + 1, r + 1);
		if (_ != T) printf("\n");
	}
	return 0;
}