#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int m = 256;
int n, l, k;
int a[205];
double dp[205][256][512];
double p[205],q[205];

int main(int argc, char** argv) {
	freopen("in", "r", stdin);
	scanf("%d%d%d", &n, &l, &k);
	for (int i = 0; i < n; ++i){ scanf("%lf", &p[i]);p[i] /= 100.0;q[i] = 1.0 - p[i]; }
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	dp[0][0][m + k] = 1.0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			for (int b = 0; b < 512; ++b) {
				dp[i][j+1][min(b + a[i-1],m + n)] += dp[i-1][j][b] * p[i-1];
				dp[i][j][b] += dp[i-1][j][b] * q[i-1];
			}
		}
	}
	double ans = 0.0;
	for (int j = l; j <= n; ++j) {
		for (int b = m; b < 512; ++b)
			ans += dp[n][j][b];
	}
	printf("%.12f\n", ans);
	return 0;
}

