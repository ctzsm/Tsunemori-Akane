#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long x[2005], y[2005], l[2005];
int main() {
//    freopen("in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
	cin >> x[i] >> y[i] >> l[i];
    }
    for (int j = n; j < m + n; ++j) {
	cin >> x[j] >> y[j] >> l[j];
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
	for (int j = n;j < n + m; ++j) {
	    if (y[j] <= y[i] || y[j] >= y[i] + l[i]) continue;
	    if (x[i] <= x[j] || x[i] >= x[j] + l[j]) continue;
	    long long cx = x[i], cy = y[j];
	    long long leny = min(abs(y[i] - cy), abs(y[i] + l[i] - cy));
	    long long lenx = min(abs(x[j] - cx), abs(x[j] + l[j] - cx));
//            cout << "lenx = " << lenx << " leny = " << leny << endl;
	    ans = max(ans, min(leny, lenx));
	}
    }
    cout << ans << endl;
}
