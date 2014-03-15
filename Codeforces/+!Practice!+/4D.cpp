#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct env{
	int w,h;
	int id;
	bool operator < (const env& e)const{
		if(w == e.w) return h < e.h;
		return w < e.w;
	}
}enve[5005];
int n,w,h;
int dp[5005][2];
int out[5005];
int main(int argc, char** argv) {
//	freopen("in","r",stdin);
	scanf("%d%d%d",&n,&w,&h);
	for(int i = 0;i < n; ++i){
		scanf("%d%d",&enve[i].w,&enve[i].h);
		enve[i].id = i + 1;
	}
	sort(enve,enve+n);
	memset(dp,-1,sizeof(dp));
	bool flag = false;
	for(int i = 0;i < n; ++i)
		if(enve[i].h > h && enve[i].w > w){ dp[i][0] = 1;flag = true; } 
		else dp[i][0] = 0;
	if(!flag){
		printf("0\n");return 0;
	}
	int end,ans = 0;
	for(int i = 1;i < n; ++i){
		if(dp[i][0] == 0) continue;
		int now = 0;
		for(int j = 0;j < i; ++j){
			if(dp[j][0] > now && enve[i].w > enve[j].w && enve[i].h > enve[j].h){
				now = dp[j][0];
				dp[i][1] = j;
			}
		}
		dp[i][0] += now;
		if(ans < dp[i][0]){
			ans = dp[i][0];end = i;
		}
	}
	printf("%d\n",ans);
	int cnt = 0;
	while(end != -1){
		out[cnt++] = enve[end].id;
		end = dp[end][1];
	}
	for(int i = cnt - 1;i >= 0; --i) printf("%d ",out[i]);
	return 0;
}

