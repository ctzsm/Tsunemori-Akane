#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

int n;
map<int, int> s;
int main(int argc, char** argv) {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int x; scanf("%d", &x);
        if(x == 0) continue;
        s[x]++;
    }
    int ans = 0;
    for(map<int, int>::iterator it = s.begin(); it != s.end(); ++it){
        if((*it).second == 2) ans++;
        if((*it).second > 2){
            ans = -1; break;
        }
    }
    printf("%d\n", ans);
    return 0;
}

