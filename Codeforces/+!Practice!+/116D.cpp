#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m;
char g[155][155];
int pos[155][2],ans[155];
int main(int argc, char** argv) {
	freopen("in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n; ++i) scanf("%s",g[i] + 1);
	for(int i = 1;i <= n; ++i){
		bool flag = true;
		for(int j = 1;j <= m; ++j){
			if(g[i][j] == 'W'){
				pos[i][0] = j;flag = false;break;
			}
		}
		if(flag){ pos[i][0] = pos[i][1] = -1;continue; }
		for(int j = m;j >= 0; --j){
			if(g[i][j] == 'W'){
				pos[i][1] = j;break;
			}
		}
	}
	ans[1] = pos[1][1] == -1 ? 0 : pos[1][1] - 1;
	int nowj = (pos[1][1] == -1) ? 1 : pos[1][1];
	for(int i = 2;i <= n; ++i){
		ans[i] = ans[i-1] + 1;
		if(i & 1){
			if(pos[i][0] != -1 && pos[i][0] < nowj){
				ans[i] += nowj - pos[i][0];
				ans[i] += pos[i][1] - pos[i][0];
				nowj = pos[i][1];
			}else if(pos[i][0] != -1){
				ans[i] += pos[i][1] - nowj;
				nowj = pos[i][1];
			}
		}else{
			if(pos[i][1] > nowj){
				ans[i] += pos[i][1] - nowj;
				ans[i] += pos[i][1] - pos[i][0];
				nowj = pos[i][0];
			}else if(pos[i][1] != -1){
				ans[i] += nowj - pos[i][0];
				nowj = pos[i][0];
			}
		}
//		printf("%d\n",ans[i]);
	}
	bool flag = true;
	for(int i = n;i >= 1; --i){
		if(pos[i][1] != -1) { printf("%d\n",ans[i]);flag = false;break; }
	}
	if(flag) printf("0\n");
	return 0;
}

