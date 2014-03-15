#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int n,a[1005];
int dp[1005][1005],pre[1005][1005];
int dfs(int i,int j){
	int& ret = dp[i][j];
	if(ret != -1){
		return ret;
	}else if(i >= n){
		return ret = 0;
	}else if(j >= n){
		return a[i];
	}else if(j + 1 >= n){
		return ret = max(a[i],a[j]);
	}else{
		ret = 0x7fffffff;
		int t =  max(a[i],a[j]) + dfs(j + 1,j + 2);
		if(ret > t) ret = t,pre[i][j] = 0;
		t = max(a[i],a[j+1]) + dfs(j,j + 2);
		if(ret > t) ret = t,pre[i][j] = 1;
		t = max(a[j],a[j+1]) + dfs(i,j + 2);
		if(ret > t) ret = t,pre[i][j] = 2;
		return ret;
	}
}
int main(int argc, char** argv) {
//	freopen("in","r",stdin);
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for(int i = 0;i < n; ++i) scanf("%d",&a[i]);
	printf("%d\n",dfs(0,1));
	
	vector<pair<int,int> > ans;
	for(int i = 0,j = 1;;){
		if(i >= n) break;
		else if(j >= n){
			ans.push_back(make_pair(i,-1));
			break;
		}else if(j + 1 >= n){
			ans.push_back(make_pair(i,j));
			break;
		}else{
			if(pre[i][j] == 0){
				ans.push_back(make_pair(i,j));
				i = j + 1;
				j = j + 2;
			}
			if(pre[i][j] == 1){
				ans.push_back(make_pair(i,j+1));
				i = j;
				j = j + 2;
			}
			if(pre[i][j] == 2){
				ans.push_back(make_pair(j,j+1));
				j = j + 2;
			}
		}
	}
	for(int i = 0;i < ans.size(); ++i){
		if(ans[i].second == -1) printf("%d\n",ans[i].first + 1);
		else printf("%d %d\n",ans[i].first + 1,ans[i].second + 1);
	}
	return 0;
}

