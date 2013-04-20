#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

int n;
char s[1005];

int main(int argc, char** argv) {
//    freopen("in", "r", stdin);
    scanf("%d%s", &n, s + 1);
    int begin = 0, end = 0, inter = 0;
    bool L = false, R = false;
    for(int i = 1; i <= n; ++i){
        if(s[i] == '.') continue;
        if(begin == 0) begin = i;
        end = i;
        if(s[i] == 'L') L = true;
        if(s[i] == 'R') R = true;
        if(s[i] == 'R' && s[i+1] == 'L') inter = i;
    }
    if(L && R){
        printf("%d %d\n", begin, inter);
        return 0;
    }
    if(L){
        printf("%d %d\n", end, begin - 1);
        return 0;
    }
    if(R){
        printf("%d %d\n", begin, end + 1);
    }
    return 0;
}

