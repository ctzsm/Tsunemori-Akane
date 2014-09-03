#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

int N, K;
char p[2][1000005];
int main() {
	freopen("in", "r", stdin);
	scanf("%d%d%s", &N, &K, p[0]);
	int now = 0, nxt = 1;
	for (int i = 0; i < N; ++i) p[0][i] -= 'A';
	for (int i = 31; i >= 0; --i) {
		if (K & (1 << i)) {
			int j = 1 << i;
			for (int k = 0; k < N; ++k) 
				p[nxt][k] = p[now][k] ^ p[now][(k + j) % N];
			std::swap(now, nxt);
		}
	}
	for (int i = 0; i < N; ++i) putchar(p[now][i] + 'A');
	putchar('\n');
	return 0;
}