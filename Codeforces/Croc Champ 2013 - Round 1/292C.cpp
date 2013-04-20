#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n;
bool v[10], valid[256];
int need = 0, exist[256], d[256], num[256][10], q[20];
vector<vector<int> > ans;

int main(int argc, char** argv) {
    freopen("in", "r", stdin);
    scanf("%d", &n);
    if (n > 6) { puts("0"); return 0;}
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        v[x] = true;
        need |= 1 << x;
    }
    memset(d, 0, sizeof(d));
    num[0][d[0]++] = 0, exist[0] = 1, valid[0] = v[0];
    for (int i = 1; i < 256; ++i) {
        int x = i; valid[i] = true; exist[i] = 0;      
        while(x){
            int t = x % 10;
            if(!v[t]) valid[i] = false;
            exist[i] |= 1 << t;
            num[i][d[i]++] = t;
            x /= 10;
        }
    }
    for(int w = 0; w < 256; ++w) if(valid[w]){
        for(int x = 0; x < 256; ++x) if(valid[x]){
            for(int y = 0; y < 256; ++y) if(valid[y]){
                if((exist[w] | exist[x] | exist[y]) == need){
                    for(int z = 0; z < 256; ++z) if(valid[z]){
                        int l = 0;
                        for(int i = d[w] - 1; i >= 0; --i) q[l++] = num[w][i];
                        for(int i = d[x] - 1; i >= 0; --i) q[l++] = num[x][i];
                        for(int i = d[y] - 1; i >= 0; --i) q[l++] = num[y][i];
                        for(int i = d[z] - 1; i >= 0; --i) q[l++] = num[z][i];
                        bool ok = true;
                        for(int i = 0, j = l - 1; i < j; ++i, --j)
                            if(q[i] != q[j]){
                                ok = false; break;
                            }
                        if(ok){
                            vector<int> v;
                            v.push_back(w);
                            v.push_back(x);
                            v.push_back(y);
                            v.push_back(z);
                            ans.push_back(v);
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); ++i){
        printf("%d.%d.%d.%d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
    }
    return 0;
}

