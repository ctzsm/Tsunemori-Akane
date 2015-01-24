#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int h[100000], s[100000], nCase = 1;
int main() {
	while (true) {
		int n = 0;
		while (true) {
			scanf("%d", &h[n++]);
			if (h[n - 1] == -1) break;
		}
		n --;
		if (h[0] == -1) break;
		int L = 0;
		for (int i = 0; i < n; ++i) {
			int lo = 1, hi = L;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (s[mid] >= h[i]) lo = mid + 1;
				else hi = mid - 1;
			}
			s[lo] = h[i];
			L = max(L, lo);
			// for (int j = 1; j <= L; ++j) printf("%d ", s[j]); printf("\n");
		}
		printf("Test #%d:\n  maximum possible interceptions: %d\n\n", nCase++, L);
	}
	return 0;
}