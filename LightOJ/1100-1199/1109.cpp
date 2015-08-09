#include <cstdio>
#include <algorithm>

using namespace std;

int a[1005], d[1005];
bool cmp(const int x, const int y) {
	if (d[x] == d[y]) return x > y;
	return d[x] < d[y];
}
void init() {
	for (int i = 1; i <= 1000; ++i)
		for (int j = i; j <= 1000; j += i)
			d[j] ++;
	for (int i = 1; i <= 1000; ++i) a[i] = i;
	sort(a + 1, a + 1001, cmp);
}
int main() {
	freopen("in", "r", stdin);
	init();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n; scanf("%d", &n);
		printf("Case %d: %d\n", _, a[n]);
	}
}