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

const int N = 1000000;
int n;
bool isNotPrime[1000005];
int getPrime() {
	isNotPrime[0] = isNotPrime[1] = true;
	for (int i = 2; i <= N; ++i) {
		if (!isNotPrime[i]) {
			for (int j = i + i; j <= N; j += i) {
				isNotPrime[j] = true;
			}
		}
	}
}
int main() {
	// freopen("in", "r", stdin);
	getPrime();
	scanf("%d", &n);
	for (int i = 4; i < n; ++i) {
		if (isNotPrime[i] && isNotPrime[n - i]) {
			printf("%d %d\n", i, n - i);
			return 0;
		}
	}
	return 0;
}