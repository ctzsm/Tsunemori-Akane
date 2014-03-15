#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int n,k;
long long ans = 0;
long long dp[50005][505];
vector<int> adj[50005];
void dfs(int now,int fa){
	dp[now][0] = 1;
	for(int i = 0;i < adj[now].size(); ++i){
		int u = adj[now][i];
		if(u != fa){
			dfs(u,now);
			for(int j = 1;j <= k; ++j) ans += dp[now][j-1] * dp[u][k-j];
			for(int j = 1;j <= k; ++j) dp[now][j] += dp[u][j-1];
		}
	}
}
int main(int argc, char** argv) {
//	freopen("in","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i = 0;i < n - 1; ++i){
		int x,y;scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	cout << ans << endl;
	return 0;
}

