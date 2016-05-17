#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;
int n;
map<pair<int, int>, int> h;
int main() {
	// freopen("in", "r", stdin);
    scanf("%d", &n);
    h[make_pair(0, 1e9 + 1)] = 0;
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        auto it = h.upper_bound(make_pair(x, x));
        if (it == h.end() || it->first.first > x) {
            it --;
        }
        int idx = it->second;
        if (i)
        	printf("%d ", idx);
        pair<int, int> p = it->first;
        if (x - 1 >= p.first)
        	h[make_pair(p.first, x - 1)] = x;
        if (p.second >= x + 1)
        	h[make_pair(x + 1, p.second)] = x;
        h.erase(it);
    }
    return 0;
}
