#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int t[1005], c[1005];
int end[1005];

int main(int argc, char** argv) {
//    freopen("in", "r", stdin);
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &t[i], &c[i]);
    end[0] = t[0] + c[0];
    int ans1 = end[0], ans2 = c[0];
    int tot = c[0];
    for (int i = 1; i < n; ++i){
        if(t[i] >= end[i-1]){
            end[i] = t[i] + c[i];
            tot = c[i];
            ans2 = max(ans2, c[i]);
        }else{
            tot = 0;
            end[i] = end[i-1] + c[i];
            for(int j = 0; j < i; ++j){
                if(end[j] > t[i]){
                    tot += min(end[j] - t[i], c[j]);
                }
            }
            tot += c[i];
        }
        ans2 = max(ans2, tot);
    }
    printf("%d %d\n", end[n-1], ans2);
    return 0;
}

