#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <iostream>
#include <set>

using namespace std;

int n, m, k;
map<int, int> a;
int main(int argc, char** argv) {
//    freopen("in", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; ++i){
        int x; scanf("%d", &x);
        a[x]++;
    }
    for(int i = 0; i < m; ++i){
        int x; scanf("%d", &x);
        a[x]--;
    }
    int alice = 0, bob = 0;
    for(map<int, int>::reverse_iterator it = a.rbegin(); it != a.rend(); ++it){
        int fish = (*it).second;
        if(fish == 0) continue;
        if(fish > 0){
            alice += fish;
        }else{
            bob -= fish;
        }
        if(alice > bob){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}

