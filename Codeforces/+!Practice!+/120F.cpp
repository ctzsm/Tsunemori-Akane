#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct node{
	int now,f,len;
	node(){}
	node(int _now,int _f,int _len){now = _now,f = _f,len = _len;}
};
int n,m,ans = 0;
vector<int> adj[105];
pair<int,int> bfs(int u,int f){
	node x(u,f,0);
	queue<node> q;q.push(x);
	int len = 0,id;
	while(!q.empty()){
		x = q.front();q.pop();
		if(len < x.len){ len = x.len;id = x.now; }
		for(int i = 0;i < adj[x.now].size(); ++i){
			int v = adj[x.now][i];
			if(v == x.f) continue;
			q.push(node(v,x.now,x.len+1));
		}
	}
	return make_pair(len,id);
}

int main(int argc, char** argv) {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(int i = 0;i < n; ++i){
		scanf("%d",&m);
		for(int i = 0;i <= m; ++i) adj[i].clear();
		for(int i = 0;i < m - 1; ++i){
			int x,y;scanf("%d%d",&x,&y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		pair<int,int> p = bfs(1,0);
		p = bfs(p.second,0);
		ans += p.first;
	}
	printf("%d\n",ans);
	return 0;
}

