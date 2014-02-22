#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
struct cons {
    long long p, e;
}con[200005];
int main() {
//    freopen("in", "r", stdin);
    cin >> n >> k;
    long long m = 0;
    long long s = 0;
    for (int i = 0; i < n; ++i) {
	cin >> con[i].p >> con[i].e;
	m = max(m, con[i].p);
	s += con[i].e;
    }

    long long ans = s + 1;
    for (int i = 0; i < (1 << n); ++i) {
	long long tot = 0, score = 0;
	for (int j = 0; j < n; ++j) {
	    if (i & (1 << j)) {
		tot += con[j].e;
		score ++;
	    }
	}
	int rank = 1;
	for (int j = 0; j < n; ++j) {
	    if (i & (1 << j)) {
		if (con[j].p > score) rank++;
	    } else {
		if (con[j].p + 1 >= score) rank++;
	    }
	}
	if (rank <= k) ans = min(ans, tot);
    }
    if (ans == s + 1)
	cout << -1 << endl;
    else
	cout << ans << endl;
}
