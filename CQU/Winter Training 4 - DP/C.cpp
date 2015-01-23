#include <bits/stdc++.h>

using namespace std;

int n, x[3], f[4005];
int main() {
	freopen("in", "r", stdin);
	scanf("%d%d%d%d", &n, &x[0], &x[1], &x[2]);
	for (int i = 0; i < 3; ++i) f[x[i]] = 1;
	for (int i = 0; i < 3; ++i) {
		for (int v = x[i]; v <= n; ++v)
			if (f[v - x[i]])
				f[v] = max(f[v], f[v - x[i]] + 1);
	}
	// for (int i = 0; i <= n; ++i)
	// 	printf("%d ", f[i]); printf("\n");
	printf("%d\n", f[n]);
	return 0;
}