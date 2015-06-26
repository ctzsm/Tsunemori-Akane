#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 5000001;
vector<bool> notPrime(maxn + 2);
unsigned long long phi[maxn + 2];
int T;
void getPhi() {
	for (int i = 2; i < maxn; ++i) phi[i] = i;
	for (int i = 2; i < maxn; ++i) {
		if (!notPrime[i]) {
			phi[i] = i - 1;
			for (int j = i + i; j < maxn; j += i) {
				notPrime[j] = true;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
	for (int i = 3; i < maxn; ++i) phi[i] *= phi[i];
	for (int i = 3; i < maxn; ++i) phi[i] += phi[i - 1];
}
int main() {
	freopen("in", "r", stdin);
	getPhi();
	scanf("%d", &T);
	for (int _  = 1; _ <= T; ++_) {
		int a, b; scanf("%d%d", &a, &b);
		printf("Case %d: %llu\n", _, phi[b] - phi[a - 1]);
	}
	return 0;
}
