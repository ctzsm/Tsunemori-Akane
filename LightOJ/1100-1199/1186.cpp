#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, w[105], b[105];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &w[i]);
		for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
		int x = 0;
		for (int i = 0; i < n; ++i) x ^= b[i] - w[i] - 1;
		printf("Case %d: %s wins\n", _, x ? "white" : "black");
	}
	return 0;
}
