#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, k, kt = 0;
int f[505];
int u[10005], v[10005], kernel[10005];
bool imp[10005];
int find(int x){
    if(f[x] != x) return f[x] = find(f[x]);
    return x;
}
int main(int argc, char** argv) {
    freopen("in", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) scanf("%d%d", &u[i], &v[i]);
    for(int i = 1; i <= n; ++i) f[i] = i;
    for(int i = 1; i <= m; ++i){
        int fu = find(u[i]), fv = find(v[i]);
        if(fu != fv){
            f[fv] = fu;
            imp[i] = true;
            kernel[kt++] = i;
        }
    }
    for(int i = 1; i <= n; ++i) f[i] = i;
    for(int i = m; i >= 1; --i){
        int fu = find(u[i]), fv = find(v[i]);
        if(fu != fv){
            f[fv] = fu;
            if(!imp[i]){
                imp[i] = true;
                kernel[kt++] = i;
            }
        }
    }
    scanf("%d", &k);
    while(k--){
        int from, to; scanf("%d%d", &from, &to);
        for(int i = 1; i <= n; ++i) f[i] = i;
        for(int i = 0; i < kt; ++i){
            if(kernel[i] < from || kernel[i] > to){
                int fu = find(u[kernel[i]]);
                int fv = find(v[kernel[i]]);
                if(fu != fv){
                    f[fv] = fu;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i)
            if(f[i] == i) ans++;
        printf("%d\n", ans);
    }
    return 0;
}

