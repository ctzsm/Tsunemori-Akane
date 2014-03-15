#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

char s[505];
int K, n;
int dp[505][505]; // pos , times
int record[505][505];

void output(int begin,int len){
	if(len & 1){
		for(int i = 0;i < len / 2; ++i) putchar(s[begin + i]);
		putchar(s[begin + len /2]);
		for(int i = len / 2 - 1;i >= 0; --i) putchar(s[begin + i]);
	}else{
		for(int i = 0;i < len / 2; ++i) putchar(s[begin + i]);
		for(int i = len / 2 - 1;i >= 0; --i) putchar(s[begin + i]);
	}
}
int main(int argc, char** argv) {
	freopen("in", "r", stdin);
	scanf("%s%d", s, &K);
	n = strlen(s);
	memset(dp,-1,sizeof(dp));
	dp[0][0] = dp[1][1] = 0;
	record[1][1] = 1;
	for(int i = 2;i <= n; ++i){
		for(int j = 1;j <= i; ++j){
			int cnt = 0;
			for(int k = 0;k < j; ++k){
				if(s[i - j + k] != s[i - 1 - k])
					cnt++;
			}
			cnt /= 2;
			for(int k = 1;k <= K; ++k){
				if(i - j < k - 1) break;
				if(dp[i - j][k - 1] == -1) continue;
				if(dp[i][k] == -1 || dp[i][k] > dp[i-j][k-1] + cnt){
					dp[i][k] = dp[i-j][k-1] + cnt;
					record[i][k] = j;
				}
			}
		}
	}
	int i = n,j,ans = 0x3fffffff;
	for(int k = 1;k <= K; ++k){
		if(ans > dp[n][k]){
			ans = dp[n][k];
			j = k;
		}
	}
	printf("%d\n",ans);
	vector<int> lena;
	while(i > 0){
		lena.push_back(record[i][j]);
		i -= record[i][j];
		j --;
	}
	reverse(lena.begin(),lena.end());
	int len = 0;
	output(len,lena[0]);
	for(int i = 1;i < lena.size(); ++i){
		putchar('+');
		len += lena[i - 1];
		output(len,lena[i]);
	}
	printf("\n");
	return 0;
}

