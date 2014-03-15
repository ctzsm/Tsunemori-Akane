#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int mod = 100000000;
int n1, n2, k1, k2;
int dp[105][105][15][2];
int ans = 0;

int main(int argc, char** argv) {
//	freopen("in", "r", stdin);
	scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
	dp[0][0][0][0] = dp[0][0][0][1] = 1;
	for (int i = 0; i <= n1; ++i) {
		for (int j = 0; j <= n2; ++j) {
			if (i == 0 && j == 0) continue;
			if (i > 0) {
				for (int a = 0; a <= k2; ++a) {
					dp[i][j][1][0] += dp[i - 1][j][a][1];
					dp[i][j][1][0] %= mod;
				}
				for (int a = 1; a < k1; ++a) {
					dp[i][j][a + 1][0] += dp[i - 1][j][a][0];
					//					if(i == 1 && a == 1) printf("%d\n",dp[i][0][a][0]);
					dp[i][j][a + 1][0] %= mod;
				}
			}
			if (j > 0) {
				for (int a = 0; a <= k1; ++a) {
					dp[i][j][1][1] += dp[i][j - 1][a][0];
					dp[i][j][1][1] %= mod;
				}
				for (int a = 1; a < k2; ++a) {
					dp[i][j][a + 1][1] += dp[i][j - 1][a][1];
					dp[i][j][a + 1][1] %= mod;
				}
			}
		}
	}
	for (int i = 1; i <= k1; ++i) {
		ans += dp[n1][n2][i][0];
//		printf("%d ", dp[n1][n2][i][0]);
		ans %= mod;
	}
//	printf("\n");
	for (int i = 1; i <= k2; ++i) {
		ans += dp[n1][n2][i][1];
//		printf("%d ", dp[n1][n2][i][1]);
		ans %= mod;
	}
//	printf("\n");
	//	printf("\n%d\n", dp[2][3][0][0]);
	printf("%d\n", ans);
	return 0;
}

