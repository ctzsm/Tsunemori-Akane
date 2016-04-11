#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const long long maxn = 1LL << 32;
unsigned int not_prime[1 << 28 | 1];
inline bool get_bit(long long x) {
	long long d = x / 32, r = x % 32;
	return not_prime[d] & (1u << r);
}
inline void set_bit(long long x) {
	long long d = x / 32, r = x % 32;
	not_prime[d] |= 1u << r;
}
unsigned int primes[203280222], pcnt = 0;
void get_prime() {
	FILE *fp = fopen("primes.txt", "r");
	fscanf(fp, "%d", &pcnt);
	for (int i = 0; i < pcnt; ++i) {
		int p; fscanf(fp, "%d", &p);
		primes[i] = p;
		set_bit((unsigned int)p); 
	}
	fclose(fp);
	printf("%d\n", pcnt);
}
unsigned int ans[11];
int s[40];
inline void print(long long x, int n) {
	for (int i = n - 1; i >= 0; --i) putchar(s[i] + '0');
	for (int i = 2; i <= 10; ++i) printf(" %u", ans[i]);
	putchar('\n');
}
void solve() {
	long long limit = 1LL << 33;
	int N, M; scanf("%d%d", &N, &M);
	long long l = (1LL << (N - 1)) | 1, r = 1LL << N;
	int cnt = 0;
	for (long long i = l; i < r; i += 2) {
		if (get_bit(i)) continue;
		bool ok = true;
		long long x = i;
		int n = 0;
		while (x) {
			s[n++] = x & 1;
			x >>= 1;		
		}
		for (int b = 3; b < 11; ++b) {
			__int128 y = 0;
			for (int k = n - 1; k >= 0; --k)
				y = y * b + s[k];
			if (y < limit && get_bit(y)) {
				ok = false;
				break;
			}
			ok = false;
			for (int j = 0; j < pcnt; ++j) {
				if (y % primes[j] == 0) {
					ok = true;
					ans[b] = primes[j];
					break;
				}
			}
			if (!ok) break;
		}
		if (!ok) continue;
		for (int j = 0; j < pcnt; ++j) {
			if (i % primes[j] == 0) {
				ok = true;
				ans[2] = primes[j];
				break;
			}
		}
		print(i, n); cnt ++;
		if (cnt >= M) break;
	}
}
int main() {
	get_prime();
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d:\n", _);
		solve();
	}
	return 0;
}
