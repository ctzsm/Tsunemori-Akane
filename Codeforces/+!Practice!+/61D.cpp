#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> PII;
int n,target;
long long ans = 0,sum = 0;
vector<PII> adj[100005];
bool visited[100005];
void dfs(int id,int depth){
	visited[id] = true;
	if(ans < depth){
		ans = depth,target = id;
	}
	for(int i = 0;i < adj[id].size(); ++i){
		PII v = adj[id][i];
		if(visited[v.first]) continue;
		dfs(v.first,depth + v.second);
	}
}
int main(int argc, char** argv) {
	freopen("in","r",stdin);
	scanf("%d",&n);
	for(int i = 0;i < n - 1; ++i){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		adj[x].push_back(make_pair(y,z));
		adj[y].push_back(make_pair(x,z));
		sum += z;
	}
	memset(visited,false,sizeof(visited));
	ans = 0,target = 1;
	dfs(0,0);
	memset(visited,false,sizeof(visited));
	ans = 0;
	dfs(target,0);
	cout << sum * 2 - ans << endl;
	return 0;
}

