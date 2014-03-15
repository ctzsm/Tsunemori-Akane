#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int a[15], b[15], c[15], d[15];
int dp[1005][105][15];

int main(int argc, char** argv) {
	freopen("in", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &c[0], &d[0]);
	for (int i = 1; i <= m; ++i) scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
	for (int i = 0; i + c[0] <= n; ++i) dp[i + c[0]][0][0] = max(dp[i + c[0]][0][0], dp[i][0][0] + d[0]);
	for (int kind = 1; kind <= m; ++kind) {
		for (int v = 0; v <= a[kind - 1]; ++v){
			for (int i = 0; i <= n; ++i) {
				dp[i][0][kind] = max(dp[i][0][kind],dp[i][v][kind-1]);
			}
		}
		for (int v = 0; v + b[kind] <= a[kind]; ++v) {
			for (int i = 0; i + c[kind] <= n; ++i) {
				dp[i + c[kind]][v + b[kind]][kind] = max(dp[i + c[kind]][v + b[kind]][kind],dp[i][v][kind] + d[kind]);
			}
		}
	}
	int ans = 0;
	for (int v = 0; v <= 100; ++v) for (int i = 0; i <= n; ++i) ans = max(ans, dp[i][v][m]);
	printf("%d\n", ans);
	return 0;
}

