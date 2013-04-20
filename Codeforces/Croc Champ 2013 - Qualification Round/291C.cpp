#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

int n, k;
map<unsigned int, int> h;
unsigned int IP[100005];
int main(int argc, char** argv) {
//    freopen("in", "r", stdin);
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i){
        unsigned int a, b, c, d;
        scanf("%u.%u.%u.%u", &a, &b, &c, &d);
        IP[i] = (a << 24) + (b << 16) + (c << 8) + d; 
    }
    unsigned int ans = 0;
    bool flag = false;
    for(int i = 31; i >= 0; --i){
        h.clear();
        ans += 1u << i;
        for(int j = 0; j < n; ++j){
            h[ans & IP[j]] ++;
        }
        if(h.size() == k){
            flag = true;
            break;
        }
    }
    if(flag){
        printf("%u.%u.%u.%u\n", ans >> 24, (ans >> 16) & 255, (ans >> 8) & 255, ans & 255);
    }else{
        printf("-1\n");
    }
    return 0;
}

