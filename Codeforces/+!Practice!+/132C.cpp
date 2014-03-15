#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n,len;
char s[105];
int d[] = {-1,1};
int dp[105][55][2][2]; //instruction changes face right/left
int main(int argc, char** argv) {
	freopen("in","r",stdin);
	scanf("%s%d",s,&n);
	len = strlen(s);
	for(int i = 0;i <= len; ++i) for(int j = 0;j <= n; ++j) dp[i][j][0][0] = dp[i][j][1][0] = -0x3ffffff,dp[i][j][0][1] = dp[i][j][1][1] = 0x3ffffff;
	dp[0][0][0][0] = dp[0][0][0][1] = dp[0][0][1][0] = dp[0][0][1][1] = 0;
	for(int i = 0;i < len; ++i){
		for(int j = 0;j <= n; ++j){
			for(int k = 0;k < 2; ++k){
				if(dp[i][j][k][1] > dp[i][j][k][0]) continue;
				for(int jj = j + (s[i] == 'T' ? 0 : 1);jj <= n; jj += 2){
					dp[i+1][jj][k][0] = max(dp[i+1][jj][k][0],dp[i][j][1-k][0]);
					dp[i+1][jj][k][1] = min(dp[i+1][jj][k][1],dp[i][j][1-k][1]);
				}
				for(int jj = j + (s[i] == 'F' ? 0 : 1);jj <= n; jj += 2){
					dp[i+1][jj][k][0] = max(dp[i+1][jj][k][0],dp[i][j][k][0] + d[k]);
					dp[i+1][jj][k][1] = min(dp[i+1][jj][k][1],dp[i][j][k][1] + d[k]);
				}
			}
		}
	}
	int ans = 0;
	for(int k = 0;k < 2; ++k){
		ans = max(ans,abs(dp[len][n][k][0]));
		ans = max(ans,abs(dp[len][n][k][1]));
	}
	printf("%d\n",ans);
	return 0;
}

