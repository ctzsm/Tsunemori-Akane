#include <bits/stdc++.h>

using namespace std;

long long N, K, C, X;
long long A[3005], B[3005];
long long M[3005][3005], F[3005][3005], G[3005][3005];
void main2() {
	cin >> N >> K >> C >> X;
	for (int i = 1; i <= N; ++i) cin >> A[i];
	for (int i = 1; i <= N; ++i) cin >> B[i];
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			M[i][j] = (A[i] * i + B[j] * j + C) % X;
	for (int i = 1; i <= N; ++i) {
		map<long long, int> s;
		for (int j = 1; j <= N; ++j) {
			s[M[i][j]] ++;
			if (j >= K) {
				F[i][j - K + 1] = (*s.rbegin()).first;
				s[M[i][j - K + 1]] --;
				if (s[M[i][j - K + 1]] == 0)
					s.erase(M[i][j - K + 1]);
			}
		}
	}
	for (int j = 1; j <= N - K + 1; ++j) {
		map<long long, int> s;
		for (int i = 1; i <= N; ++i) {
			s[F[i][j]] ++;
			if (i >= K) {
				G[i - K + 1][j] = (*s.rbegin()).first;
				s[F[i - K + 1][j]] --;
				if (s[F[i - K + 1][j]] == 0)
					s.erase(F[i - K + 1][j]);
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= N - K + 1; ++i) {
		for (int j = 1; j <= N - K + 1; ++j) {
			ans += G[i][j];
		}
	}
	cout << ans << endl;
}
int main() {
	// freopen("in", "r", stdin);
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		main2();
	}
	return 0;
}
