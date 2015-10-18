#include <bits/stdc++.h>

using namespace std;

int P, S[105], N, M;
map<string, vector<int> > h;
struct ath {
	int score;
	string name;
	ath() {}
	ath(int _v, string _n): score(_v), name(_n) {}
	bool operator < (const ath& x) const {
		if (score == x.score)
			return name < x.name;
		return score > x.score;
	}
};
void main2() {
	scanf("%d", &P);
	for (int i = 0; i < P; ++i) scanf("%d", S + i);
	scanf("%d", &N);
	h.clear();
	for (int i = 0; i < N; ++i) {
		int W; scanf("%d", &W);
		for (int i = 0; i < P; ++i) {
			string name; cin >> name;
			if (h.find(name) == h.end())
				h[name] = vector<int>();
			h[name].push_back(W * S[i]);
		}
	}
	scanf("%d", &M);
	vector<ath> va;
	for (auto it = h.begin(); it != h.end(); ++it) {
		vector<int>& v = (*it).second;
		sort(v.begin(), v.end(), greater<int>());
		int score = 0;
		for (int i = 0; i < v.size() && i < M; ++i) 
			score += v[i];
		va.push_back(ath(score, (*it).first));
	}
	sort(va.begin(), va.end());
	for (int i = 0, j = 1, now = 0; i < va.size(); ++i) {
		if (now != va[i].score) j = i + 1;
		cout << j << ": " << va[i].name << endl;
		now = va[i].score;
	}
}
int main() {
	// freopen("in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d:\n", _);
		main2();
	}
	return 0;
}
