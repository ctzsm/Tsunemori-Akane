#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

int n, m, k, A, B;
int x[5005], y[5005], z[5005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n); for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
	scanf("%d", &m); for (int i = 0; i < m; ++i) scanf("%d", &y[i]);
	scanf("%d", &k); for (int i = 0; i < k; ++i) scanf("%d", &z[i]);
	scanf("%d%d", &A, &B);
	std::sort(x, x + n);
	double ratio = 0.0;
	for (int i = 0; i < m; ++i) 
		for (int j = 0; j < k; ++j) 
			ratio = std::max(ratio, 1.0 * B * y[i] / (A * z[j] + B * y[i]));
	printf("%.10f\n", sqrt(ratio * x[n-1] * x[n-1]));
	return 0;
}