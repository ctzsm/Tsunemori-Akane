#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

char name[105];
int k, n;
int dp[105][30][105], c[700];
int value[30][30];
char x[700], y[700];

int main(int argc, char** argv) {
	freopen("in", "r", stdin);
	scanf("%s%d%d", name + 1, &k, &n);
	for (int i = 0; i < n; ++i) {
		char s[2], t[2];
		scanf("%s%s%d", s, t, &c[i]);
		x[i] = s[0], y[i] = t[0];
		value[x[i] - 'a'][y[i] - 'a'] = c[i];
	}
	int len = strlen(name + 1);
	for (int i = 0; i <= len; ++i) for (int j = 0; j <= 26; ++j) for (int l = 0; l <= k; ++l)
				dp[i][j][l] = -0x3fffffff;
	for (int i = 0; i < 26; ++i) {
		if (name[1] - 'a' == i) dp[1][i][0] = 0;
		else dp[1][i][1] = 0;
	}
	for (int i = 2; i <= len; ++i) {
		for (int a = 0; a < 26; ++a) {
			for (int b = 0; b < 26; ++b) {
				for (int j = 0; j <= min(i, k); ++j) {
					if (name[i] - 'a' == a) dp[i][a][j] = max(dp[i][a][j],dp[i-1][b][j] + value[b][a]);
					else if(j > 0){
						dp[i][a][j] = max(dp[i][a][j],dp[i-1][b][j-1] + value[b][a]);
					}
				}
			}
		}
	}
	int ans = -0x3fffffff;
	for(int i = 0;i < 26; ++i) for(int j = 0;j <= k; ++j)
		ans = max(ans,dp[len][i][j]);
	printf("%d\n", ans);
	return 0;
}

