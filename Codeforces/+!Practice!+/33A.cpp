#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n,m,k;
int row[1005];
int main(int argc, char** argv) {
	freopen("in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	memset(row,127,sizeof(row));
	for(int i = 0;i < n; ++i){
		int r,c;scanf("%d%d",&r,&c);
		row[r] = min(row[r],c);
	}
	int ans = 0;
	for(int i = 1;i <= m; ++i) ans += row[i];
	ans = min(ans,k);
	printf("%d\n",ans);
	return 0;
}

