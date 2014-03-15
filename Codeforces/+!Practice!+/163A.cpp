#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

const int mod = 1000000007;
char s[5005],t[5005];
int dp[5005][5005];
int main(int argc, char** argv) {
	scanf("%s%s",s,t);
	int lens = strlen(s),lent = strlen(t);
	for(int i = 1;i <= lens; ++i){
		for(int j = 1;j <= lent; ++j){
			dp[i][j] = dp[i][j-1];
			if(s[i-1] == t[j-1]){ dp[i][j] = (dp[i][j] + dp[i-1][j-1] + 1) % mod; }
		}
	}
	int ans = 0;
	for(int i = 1;i <= lens; ++i) ans += dp[i][lent],ans %= mod;
	printf("%d\n",ans);
	return 0;
}

