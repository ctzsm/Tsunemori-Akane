#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N, K;
bool visited[200010];
int main() {
	freopen("in", "r", stdin);
	while (~scanf("%d%d", &N, &K)) {
		memset(visited, false, sizeof visited);
		queue<pair<int, int> > q;
		q.push(make_pair(N, 0));
		visited[N] = true;
		int upper = max(2 * K, N);
		while (!q.empty()) {
			pair<int, int> now = q.front(); q.pop();
			if (now.first == K) {
				printf("%d\n", now.second);
				break;
			}
			int x = now.first, s = now.second;
			if (0 <= x - 1 && x - 1 <= upper && !visited[x - 1]) {
				visited[x - 1] = true;
				q.push(make_pair(x - 1, s + 1));
			}
			if (0 <= x + 1 && x + 1 <= upper && !visited[x + 1]) {
				visited[x + 1] = true;
				q.push(make_pair(x + 1, s + 1));
			}
			if (0 <= x * 2 && x * 2 <= upper && !visited[x * 2]) {
				visited[x * 2] = true;
				q.push(make_pair(x * 2, s + 1));
			}
		}
	}
	return 0;
}