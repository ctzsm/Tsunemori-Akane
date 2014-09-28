/*
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n, p[100005];
pair<string, int> h[200005];
int main() {
	// freopen("in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string x, y; cin >> x >> y;
		h[(i << 1) - 1] = make_pair(x, i);
		h[(i << 1)] = make_pair(y, i);
	}
	sort(h + 1, h + 2 * n + 1);
	// for (int i = 1; i <= 2 * n; ++i) {
	// 	cout << h[i].first << " " << h[i].second << endl;
	// }
	for (int i = 1; i <= n; ++i)
		cin >> p[i];
	for (int i = 1, j = 1; i <= n && j <= 2 * n; ++i) {
		while(j <= 2 * n && h[j].second != p[i]) j++;
		if (j > 2 * n) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}