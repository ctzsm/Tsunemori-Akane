#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n,m;
int a[105],value[105][105],cnt[105];
int dp[10005];
int main(int argc, char** argv) {
	freopen("in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n; ++i){
		scanf("%d",&cnt[i]);
		int limit = cnt[i];
		for(int j = 1;j <= limit; ++j) scanf("%d",&a[j]);
		for(int j = 1;j <= limit; ++j) a[j] += a[j-1];
		for(int j = 1;j <= limit; ++j){
			for(int k = 0;k <= j; ++k){
				value[i][j] = max(value[i][j],a[k] + a[limit] - a[limit - (j - k)]);
			}
		}
	}
	for(int i = 1;i <= n; ++i){
		for(int v = m;v >= 0; --v){
			for(int j = 0;j <= min(cnt[i],v); ++j){
//				if(v < j){ dp[i][v] = dp[i-1][v];break; }
				dp[v] = max(dp[v],dp[v - j] + value[i][j]);
			}
		}
	}
	printf("%d\n",dp[m]);
	return 0;
}

