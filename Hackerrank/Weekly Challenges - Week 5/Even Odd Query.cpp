#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

int N, Q;
int a[100005];
bool calc(int x, int y) {
	if (x > y) return true;
	if (a[x] & 1) return true;
	if (x == y) return false;
	if (x + 1 <= N && a[x + 1] == 0) {
		return true;
	}
	return false;
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &a[i]);
	scanf("%d", &Q);
	for (int i = 0; i < Q; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		puts(calc(x, y) ? "Odd" : "Even");
	}
	return 0;
}