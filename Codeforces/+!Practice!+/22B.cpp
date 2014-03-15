#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n,m,ans = 0;
char off[30][30];
int main(int argc, char** argv) {
	freopen("in","r",stdin);
	scanf("%d%d",&n,&m);
	memset(off,'1',sizeof(off));
//	printf("%c\n",off[0][0]);
	for(int i = 1;i <= n; ++i) scanf("%s",off[i] + 1);
	for(int i = 1;i <= n; ++i){
		for(int j = 1;j <= m; ++j){
			if(off[i][j] == '1') continue;
			bool flag = false;
			int limit = j + 1;
			for(int a = 1;a <= i; ++a){
				for(int b = 1;b < limit; ++b){
					if(off[i-a+1][j-b+1] == '0'){
						ans = max(ans,a+a+b+b);
					}else{
						if(b == 1) flag = true;
						limit = b;
						break;
					}
				}
				if(flag) break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

