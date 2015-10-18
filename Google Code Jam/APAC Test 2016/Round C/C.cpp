#include <bits/stdc++.h>

using namespace std;

int N, M;
bool f[1 << 16];
int a[16][16];
int x[16];
vector<int> g[6][6];
void init() {
	for (int N = 1; N <= 4; ++N) {
		int n = 1 << N;
		for (int i = 1; i <= N + 1; ++i) {
			memset(x, 0, sizeof x);
			for (int l = 0, j = n - 1; l < (1 << (i - 1)); ++l, --j) x[j] = 1;
			do {
				int id = 0;
				for (int j = 0; j < n; ++j)
					id = (id << 1) | x[j];
				g[N][i].push_back(id);
			} while (next_permutation(x, x + n));
		}
	}
}
bool check(int s, int t, int r) {
	int n = (1 << N);
	for (int i = 0; i < n; ++i) if (s & (1 << i)) {
		if (a[i][r] & t) return false;
	}
	for (int j = 0; j < n; ++j) if (t & (1 << j)) {
		if (a[j][r] & s) return false;
	}
	return true;
}
void main2() {
	scanf("%d%d", &N, &M);
	memset(f, false, sizeof f);
	memset(a, false, sizeof a);
	for (int i = 0; i < M; ++i) {
		int E, K, B; scanf("%d%d%d", &E, &K, &B);
		E --;
		int flag = 0;
		for (int j = 0; j < B; ++j) {
			int X; scanf("%d", &X); X --;
			flag ^= 1 << X;
		}
		for (int j = 1; j <= K; ++j)
			a[E][j] = flag;
	}
	int m = 1 << (1 << N), n = 1 << N;
	for (int i = 0; i < n; ++i) f[1 << i] = true;
	for (int i = 1; i <= N; ++i) {
		vector<int>& v = g[N][i];
		vector<int>& u = g[N][i + 1];
		for (int j = 0; j < u.size(); ++j) {
			for (int k = 0; k < v.size(); ++k) {
				if (u[j] & v[k] != v[k]) continue;
				if (!f[v[k]]) continue;
				if (!f[u[j] ^ v[k]]) continue;
				f[u[j]] |= check(u[j] ^ v[k], v[k], i);
				if (f[u[j]]) break;
			}
		}
	}
	puts(f[m - 1] ? "YES" : "NO");
}
int main() {
	// freopen("in", "r", stdin);
	freopen("C-large-practice.in", "r", stdin);
	freopen("C-large-practice1.out", "w", stdout);
	init();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		main2();
	}
	return 0;
}
