#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <iostream>
#include <algorithm>

const int N = 1000000;
std::map<int, int> h;
long long C[N + 5];
inline int lowbit(int x) {
	return x & -x;
}
void modify(int p, long long x) {
	while (p <= N) {
		C[p] += x;
		p += lowbit(p);
	}
}
long long sum(int p) {
	long long res = 0;
	while (p) {
		res += C[p];
		p -= lowbit(p);
	}
	return res;
}
void binary_output(int x) {
	std::bitset<32> b(x);
	std::cout << b << " ";
}
int end[1000005];
std::set<int> e;
int updateInter(int x, int m, int weight) {
	while (x <= N) {
		modify(x, m * weight);
		x += lowbit(x);
	}
	return x - N;
}
void update(int pos, int M, int plus) {
	for (int i = 1; i <= 50; ++i) {
		updateInter(updateInter(updateInter(pos, M, 1), M, 1), M, 998);
		pos += plus;
		if (pos > N) pos -= N;
	}
}
int Q;
char op[2];
int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	scanf("%d", &Q);
	while (Q--) {
		scanf("%s", op);
		if (op[0] == 'U') {
			int pos, m, plus; scanf("%d%d%d", &pos, &m, &plus);
			update(pos, m, plus);
		} else {
			int pos1, pos2; scanf("%d%d", &pos1, &pos2);
			printf("%lld\n", sum(pos2) - sum(pos1 - 1));
		}
	}
	return 0;
}