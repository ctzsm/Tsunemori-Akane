#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

int t, sx, sy, ex, ey;
string s;
int east = 0, west = 0, north = 0, south = 0;
int main(int argc, char** argv) {
//    freopen("in", "r", stdin);
    cin >> t >> sx >> sy >> ex >> ey >> s;
    for(int i = 0; i < t; ++i){        
        if(s[i] == 'E' && sx - ex < 0){
            sx++; 
        }
        if(s[i] == 'W' && sx - ex > 0){
            sx--;
        }
        if(s[i] == 'N' && sy - ey < 0){
            sy++;
        }
        if(s[i] == 'S' && sy - ey > 0){
            sy--;
        }
        if(sx == ex && sy == ey){
            printf("%d\n", i + 1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}

