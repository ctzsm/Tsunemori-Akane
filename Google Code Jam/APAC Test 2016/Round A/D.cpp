#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int S, R, C;
int o[1000005];
char s[2];
struct node {
	int r, c;
	node* prev;
	node() {}
	node(int r, int c): r(r), c(c) { prev = NULL; }
};
inline long long HASH(int r, int c) {
	return 1LL * r * C + c;
}
void collect(node* p) {
	while (p) {
		node* q = p;
		p = p->prev;
		delete q;
	}
}
void main2(bool flag) {
	unordered_set<long long> f, g;
	scanf("%d%d%d", &S, &R, &C);
	node* head = new node(1, 1);
	node* tail = head;
	memset(o, 0, sizeof o);
	int t = 0;
	for (int i = 0; i < S; ++i) {
		scanf("%d%s", &t, s);
		o[t] = s[0] == 'R' ? 1 : 2;
	}
	f.insert(HASH(1, 1));
	int dir = 0, limit = t + max(R, C) + 10, ans = 1;
	for (int i = 1; i < limit; ++i) {
		int nr = head->r + dy[dir];
		if (nr > R) nr = 1;
		else if (nr < 1) nr = R;
		int nc = head->c + dx[dir];
		if (nc > C) nc = 1;
		else if (nc < 1) nc = C;
		long long pa = HASH(nr, nc);
		long long ta = HASH(tail->r, tail->c);
		if (((nc + nr) & 1) && g.find(pa) == g.end()) {
			if (flag && false) printf("%d %d\n", nr, nc);
			node* p = new node(nr, nc);
			head->prev = p;
			head = p;
			f.insert(pa);
			g.insert(pa);
			ans++;
		} else {
			node* p = tail;
			tail = tail->prev;
			f.erase(ta);
			if (f.find(pa) != f.end()) break;
			p->r = nr, p->c = nc, p->prev = NULL;
			head->prev = p;
			head = p;
			f.insert(pa);
		}

		if (i <= t && o[i]) {
			if (o[i] == 1) dir += 1;
			else if (o[i] == 2) dir += 3;
			if (dir >= 4) dir -= 4;
		}
	}
	// printf("%d\n", (int)f.size());
	collect(tail);
	printf("%d\n", ans);
}
int main() {
	// freopen("in", "r", stdin);
	freopen("D-large-practice.in", "r", stdin);
	freopen("D-large-practice.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		main2(_ == 2);
	}
	return 0;
}
