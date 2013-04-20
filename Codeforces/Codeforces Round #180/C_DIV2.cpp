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

string a, b;
int main(int argc, char** argv) {
//    freopen("in", "r", stdin);
    cin >> a >> b;
    int cnta = 0, cntb = 0;
    for(int i = 0; i < a.size(); ++i)
        if(a[i] == '1') cnta++;
    for(int i = 0; i < b.size(); ++i)
        if(b[i] == '1') cntb++;
    
    if(cnta >= cntb){
        puts("YES"); return 0;
    }
    if(cnta == cntb - 1 && (cnta & 1)){
        puts("YES"); return 0;
    }
    puts("NO");
    return 0;
}
