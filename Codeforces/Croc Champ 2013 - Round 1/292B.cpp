#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int in[100005];
vector<int> adj[100005];
bool visited[100005];
void dfs(int v, int f){
    visited[v] = true;
    for(int i = 0; i < adj[v].size(); ++i){
        int u = adj[v][i];
        if(visited[u]) continue;
        dfs(u, f);
    }
}
bool connected(){
    dfs(1, 0);
    for(int i = 1; i <= n; ++i)
        if(!visited[i]) return false;
    return true;
}
int main(int argc, char** argv) {
//    freopen("in", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        in[u]++;
        in[v]++;
    }
    int cnt1 = 0, cnt2 = 0, cntn1 = 0;
    for(int i = 1; i <= n; ++i){
        if(in[i] == 1) cnt1++;
        if(in[i] == 2) cnt2++;
        if(in[i] == n - 1) cntn1++;
    }
    if(cnt1 == 2 && cnt2 == n - 2){
        puts("bus topology");
        return 0;
    }
    if(cnt1 == n - 1 && cntn1 == 1){
        puts("star topology");
        return 0;
    }
    if(cnt2 == n && connected()){
        puts("ring topology");
        return 0;
    }
    puts("unknown topology");
    return 0;
}

