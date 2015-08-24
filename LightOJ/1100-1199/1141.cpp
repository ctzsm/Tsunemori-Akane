#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1005;
bool isNotPrime[maxn];
int prime[maxn], pcnt = 0;
vector<int> p[maxn];
void getPrime() {
	for (int i = 2; i < maxn; ++i) {
		if (!isNotPrime[i]) {
			prime[pcnt++] = i;
			for (int j = i + i; j < maxn; j += i)
				isNotPrime[j] = true;
		}
	}
	for (int i = 4; i < maxn; ++i)
		for (int j = 0; prime[j] < i && j < pcnt; ++j)
			if (i % prime[j] == 0)
				p[i].push_back(prime[j]);
}
bool visited[1005];
int solve() {
	int s, t; scanf("%d%d", &s, &t);
	if (s == t) return 0;
	if (s > t) return -1;
	memset(visited, false, sizeof visited);
	queue<pair<int, int> > q;
	q.push(make_pair(s, 0)); visited[s] = true;
	while (!q.empty()) {
		int n = q.front().first, step = q.front().second;
		if (n == t) return step;
		q.pop();
		for (int i = 0; i < p[n].size(); ++i) {
			int m = n + p[n][i];
			if (m > t || visited[m]) continue;
			visited[m] = true;
			q.push(make_pair(m, step + 1));
		}
	}
	return -1;
}
int main() {
	freopen("in", "r", stdin);
	getPrime();
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
