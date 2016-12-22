#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int x[2] = {-1, 1};
char s[15], t[15];
int main() {
	// freopen("in", "r", stdin);
	scanf("%s%s", s, t);
	int ls = strlen(s), lt = strlen(t), g = 0;
	for (int i = 0; i < ls; ++i) {
		g += x[s[i] == '+'];
	}
	map<int, int> h[2];
	int cur = 0, pre = 1;
	h[pre][0] = 1;
	for (int i = 0; i < lt; ++i) {
		h[cur].clear();
		for (auto it = h[pre].begin(); it != h[pre].end(); ++it) {
			if (t[i] == '+' || t[i] == '?')
				h[cur][it->first + 1] += it->second;
			if (t[i] == '-' || t[i] == '?')
				h[cur][it->first - 1] += it->second;
		}
		swap(cur, pre);
	}
	int sum = 0;
	for (auto it = h[pre].begin(); it != h[pre].end(); ++it) {
		sum += it->second;
	}
	printf("%.10f\n", 1.0 * h[pre][g] / sum);
	return 0;
}
