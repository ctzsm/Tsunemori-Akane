#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int w,b;
double dp[1005][1005][2];
int main(int argc, char** argv) {
//	freopen("in","r",stdin);
	scanf("%d%d",&w,&b);
	for(int i = 1;i <= w; ++i) dp[i][0][1] = dp[i][0][0] = 1.0;
	for(int j = 0;j <= b; ++j) { dp[0][j][0] = 0.0;dp[0][j][1] = 1.0; }
	for(int i = 1;i <= w; ++i){
		for(int j = 1;j <= b; ++j){
			double coe = (double)(i) / (double)(i + j);
			dp[i][j][0] = coe + (1.0 - dp[i][j-1][1]) * (1.0 - coe);
			dp[i][j][1] = coe + (1.0 - dp[i-1][j-1][0]) * (1.0 - coe) * ((double)(i) / (double)(i + j - 1));
			if(j >= 2) dp[i][j][1] += (1.0 - dp[i][j-2][0]) * (1.0 - coe) * ((double)(j-1) / (double)(i + j - 1));
		}
	}
	printf("%.16f\n",dp[w][b][0]);
	return 0;
}

