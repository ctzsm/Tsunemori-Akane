#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, p[55], q[5];
long long point = 0, cnt[5];
int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
	for (int i = 0; i < 5; ++i) scanf("%d", &q[i]);
	for (int i = 0; i < n; ++i) {
		point += p[i];
		for (int j = 4; j >= 0; --j) {
			cnt[j] += point / q[j];
			point %= q[j];
		}
	}
	for (int i = 0; i < 5; ++i) printf("%lld ", cnt[i]); printf("\n");
	printf("%lld\n", point);
	return 0;
}