#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
char a[105];
int main() {
    scanf("%s", a);
    int len = strlen(a);
    char c = '0';
    int cnt = 1, ans = 0;
    for (int i = 0; i < len; ++i) {
        if (c != a[i]) {
            ans += (cnt + 1) % 2;
            cnt = 1;
            c = a[i];
        } else {
            cnt ++;
        }
    }
    ans += (cnt + 1) % 2;
    printf("%d\n", ans);
}

