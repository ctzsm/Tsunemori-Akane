#include <set>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

const long long mod = 1000000007;
long long n, k;
std::set<std::vector<int> > h[101];
inline long long MOD(long long x) {
	return (x % mod + mod) % mod;
}
long long T[2505][2505];
void task1() {
	T[1][0] = 1;
	for (int i = 2; i <= n; ++i) {
		T[i][0] = 1;
		for (int j = 1; j <= k; ++j) {
			T[i][j] = T[i][j - 1] + T[i - 1][j];
			if (j >= i) T[i][j] -= T[i - 1][j - i];
			T[i][j] = MOD(T[i][j]);
		}
	}
	for (int i = 2; i <= k; ++i) {
		T[n][i] += T[n][i - 2];
		T[n][i] %= mod;
	}
	printf("%lld ", T[n][k]);
	// printf("\n");
}
long long S[2505][2505];
void task2() {
	memset(T, 0, sizeof(T));
	for (int i = 1; i <= n + 1; ++i)
		for (int j = 1; j <= i; ++j) {
			if (i == j) {
				S[i][j] = 1;
				continue;
			}
			S[i][j] = MOD(S[i - 1][j - 1] - (i - 1) * S[i - 1][j]);
		}
	// for (int i = 1; i <= n; ++i) {
	//  for (int j = 1; j <= i; ++j) printf("\t%lld", S[i][j]);
	//  printf("\n");
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k + 1; ++j) {
			if (i + 1 - j >= 0) {
				if ((j - 1) & 1)
					T[i][j] = (mod - S[i][i + 1 - j]) % mod;
				else
					T[i][j] = S[i][i + 1 - j];
			}
		}
	}
	// for (int i = 1; i <= n; ++i) {
	//  for (int j = 1; j <= k + 1; ++j) {
	//      printf("\t%lld", T[i][j]);
	//  }
	//  printf("\n");
	// }
	long long ans2 = 0;
	for (int i = 0; i <= k + 1; ++i) ans2 += T[n][i];
	printf("%lld\n", ans2 % mod);
}
int main() {
	// for (int i = 1; i <= 7; ++i) {
	//  int cnt[10]; memset(cnt, 0, sizeof(cnt));
	//  std::queue<std::pair<std::vector<int>, int> > q;
	//  std::vector<int> v;
	//  for (int j = 1; j <= i; ++j) {
	//      v.push_back(j);
	//  }
	//  std::set<std::vector<int> > hash;
	//  hash.insert(v);
	//  q.push(std::make_pair(v, 0));
	//  while (!q.empty()) {
	//      std::pair<std::vector<int>, int> now = q.front(); q.pop();
	//      cnt[now.second] ++;
	//      for (int l = 0; l < i; ++l) {
	//          for (int r = l + 1; r < i; ++r) {
	//              std::swap(now.first[l], now.first[r]);
	//              if (hash.find(now.first) == hash.end()) {
	//                  hash.insert(now.first);
	//                  q.push(std::make_pair(now.first, now.second + 1));
	//              }
	//              std::swap(now.first[l], now.first[r]);
	//          }
	//      }
	//  }
	//  printf("%d: ", i);
	//  for (int j = 0; j < 10; ++j) printf("\t%d", cnt[j]);
	//  printf("\n");
	// }
	freopen("in", "r", stdin);
	scanf("%lld%lld", &n, &k);
	if (n == 1 && k == 0) {
		printf("1 1\n");
		return 0;
	}
	if (n == 1 && k > 0) {
		printf("0 1\n");
		return 0;
	}
	task1();
	task2();
	return 0;
}