#include <cstdio>
#include <algorithm>

using namespace std;

int P[505], W[505], v[10005];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) {
		int E, F, N; scanf("%d%d%d", &E, &F, &N);
		for (int i = 0; i < N; ++i) scanf("%d%d", &P[i], &W[i]);
		F -= E;
		for (int i = 0; i <= F; ++i) v[i] = 50000 * 500 + 10;
		v[0] = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = W[i]; j <= F; ++j) 
				v[j] = min(v[j], v[j - W[i]] + P[i]);
		}
		if (v[F] == 50000 * 500 + 10) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n", v[F]);
	}
	return 0;
}