#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = 1;
char a[1005];
int solve(char c) {
    int cnt = 0, ret = 0;
    int i = 0, j = n - 1;
    while (a[i] != c && i < n) i++;
    while (a[j] != c && j >= 0) j--;
    for (; i <= j; ++i) {
	if (a[i] == c) {
	    if (cnt % 2 == 0) ret ++, cnt = 0;
	    else cnt ++;
	} else {
	    cnt ++;
	}
    }
    return ret;
}
int main() {
    scanf("%s", a);
    n = strlen(a);
    for (char c = 'A'; c <= 'Z'; ++c) ans = max(ans, solve(c));
    printf("%d\n", ans);
}
