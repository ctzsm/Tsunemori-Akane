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

using namespace std;
double getPr(int n) {
	double ans = 0;
	for (int i = 1; i <= 100 * n; ++i) {
		double pr = 0, C = 1;
		int sign = 1;
		for (int j = 1; j <= n; ++j) {
			C = C * (n - j + 1) / j;
			pr += C * pow(1.0 * (n - j) / n, n + i - 1) * j / n * sign;
			sign = -sign;
		}
		ans += pr * i;
	}
	return ans + n;
}
int n, m;
int main() {
	long double ans = 0.0;
	n = 1000 * 1000;
	for (int i = 2; i <= n; ++i) {
		ans += 1.0 / i;
	}
	printf("%.20Lf\n", ans * n + n);
	return 0;
	freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i < 50; ++i) {
		printf("%d %f\n", i, getPr(i));
	}
	return 0;
}