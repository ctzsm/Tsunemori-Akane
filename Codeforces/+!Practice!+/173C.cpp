#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n,m;
int a[505][505];
int sum[505][505];
int square_sum(int i,int j,int d){
	return sum[i][j] + sum[i + d][j + d] - sum[i][j + d] - sum[i + d][j];
}
int main(int argc, char** argv) {
	freopen("in","r",stdin);
	
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n; ++i) for(int j = 0;j < m; ++j) scanf("%d",&a[i][j]);
	for(int i = 0;i < n; ++i) for(int j = 0;j < m; ++j) sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + a[i][j];
	
	int ans = -0x3fffffff;
	
	for(int i = 0;i < n; ++i) for(int j = 0;j < m; ++j){
		int maxd = min(min(i,n - 1 - i),min(j,m - 1 - j));
		int now = a[i][j];
		for(int d = 1;d <= maxd; ++d){
			now = square_sum(i - d,j - d,2 * d + 1) - now - a[i - d + 1][j - d];
			ans = max(ans,now);
		}
	}
	
	printf("%d\n",ans);
	return 0;
}

