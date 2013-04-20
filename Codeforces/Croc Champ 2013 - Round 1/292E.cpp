#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cassert>

using namespace std;

const int maxn = 131072 + 1;
int n, m;
int a[maxn], b[maxn];
int tree[maxn << 1];
bool self[maxn << 1], col[maxn << 1];

void PushDown(int rt){
    if(col[rt]){
        self[rt << 1] = self[rt << 1 | 1] = self[rt];
        tree[rt << 1] = tree[rt << 1 | 1] = tree[rt];
        col[rt << 1] = col[rt << 1 | 1] = col[rt];
        col[rt] = false;
    }
}
void build(int l, int r,int rt){
    self[rt] = false;
    col[rt] = false;
    tree[rt] = 0;
    if(l == r) return;
    int m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
}
void update(int L, int R, int l, int r, int rt, int v){
    if(L <= l && r <= R){
        self[rt] = true;
        col[rt] = true;
        tree[rt] = v;
//        printf("l = %d, r = %d, tree = %d\n", l, r, tree[rt])
        return;
    }
    PushDown(rt);
    int m = (l + r) >> 1;
    if(L <= m) update(L, R, l, m, rt << 1, v);
    if(R > m) update(L, R, m + 1, r, rt << 1 | 1, v);
}
bool query(int id, int l, int r, int rt, int& ans){
    if(l == r){
        ans = self[rt] ? id + tree[rt] : id;
//        printf("tree = %d, id = %d, self = %d\n", tree[rt], id, self[rt]);
        return self[rt];
    }
    PushDown(rt);
    int m = (l + r) >> 1;
    bool ret = false;
    if(id <= m) ret |= query(id, l, m, rt << 1, ans);
    else ret |= query(id, m + 1, r, rt << 1 | 1, ans);
    return ret;
}
int main(int argc, char** argv) {
    freopen("in", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    build(1, n, 1);
    while(m--){
        int t; scanf("%d", &t);
        if(t == 1){
            int x, y, k; scanf("%d%d%d", &x, &y, &k);
            update(y, y + k - 1, 1, n, 1, x - y);
        }else{
            int x, ans = 0; scanf("%d", &x);
            if(query(x, 1, n, 1, ans)){
                printf("%d\n", a[ans]);
//                printf("ans = %d\n", ans);
            }else{
                printf("%d\n", b[x]);
            }
        }
    }
    return 0;
}

