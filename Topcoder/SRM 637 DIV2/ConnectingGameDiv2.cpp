#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

const int inf = 100000000;
const int maxn = 1500;
struct CNode {
	int v, i;
	CNode(int _v, int _i): v(_v), i(_i) {}
};
vector<CNode> a[maxn];
vector<int> flow, cap;
int cur[maxn], sumd[maxn], d[maxn], pre[maxn];

void AddEdge(int u, int v, int c) {
	a[u].push_back(CNode(v, cap.size()));
	a[v].push_back(CNode(-u, cap.size()));
	cap.push_back(c);
	flow.push_back(0);
}

int SAP(int s, int t, int n) {
	memset(sumd, 0, sizeof(sumd));
	memset(cur, 0, sizeof(cur));
	memset(d, 0, sizeof(d));
	sumd[0] = n;
	pre[s] = s;
	int ans = 0;
	int now = s;
	int modify = inf;
	while (d[s] < n) {
		bool flag = false;
		if (now == s)
			modify = inf;
		for (int &j = cur[now]; j < a[now].size(); ++j) {
			int i = a[now][j].i;
			int v = a[now][j].v;
			if (v > 0 && d[now] == d[v] + 1 && flow[i] < cap[i]) {
				flag = true;
				pre[v] = now;
				now = v;
				modify = min(modify, cap[i] - flow[i]);
				break;
			}
			if (v < 0 && d[now] == d[-v] + 1 && flow[i] > 0) {
				flag = true;
				pre[-v] = now;
				now = -v;
				modify = min(modify, flow[i]);
				break;
			}
		}
		if (now == t) {
			ans += modify;
			while (now != s) {
				now = pre[now];
				if (a[now][cur[now]].v > 0)
					flow[a[now][cur[now]].i] += modify;
				else
					flow[a[now][cur[now]].i] -= modify;
			}
		}
		if (flag)
			continue;
		cur[now] = 0;
		int mind = n;
		for (int tt = 0; tt < a[now].size(); ++tt) {
			int i = a[now][tt].i;
			int v = a[now][tt].v;
			if (v > 0 && d[v] < mind && flow[i] < cap[i])
				mind = d[v];
			if (v < 0 && d[-v] < mind && flow[i] > 0)
				mind = d[-v];
		}
		sumd[d[now]]--;
		if (sumd[d[now]] == 0)
			d[s] = n;
		sumd[d[now] = mind + 1]++;
		now = pre[now];
	}
	return ans;
}
int getId(char c) {
	if ('a' <= c && c <= 'z') return c - 'a';
	if ('A' <= c && c <= 'Z') return c - 'A' + 26;
	if ('0' <= c && c <= '9') return c - '0' + 52;
	return -1;
}

int n, m;
int w[150];
bool grid[100][100], up[70], down[70];
class ConnectingGameDiv2 {
public:
	int getmin(vector<string> board) {
		n = board.size(), m = board[0].size();
		cap.clear(), flow.clear();
		memset(w, 0, sizeof w);
		memset(grid, false, sizeof grid);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				w[getId(board[i][j])] ++;
		for (int i = 0; i < 150; ++i)
			a[i].clear();
		for (int i = 1; i <= 62; ++i)
			AddEdge(i << 1, i << 1 | 1, w[i - 1]);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m - 1; ++j) {
				int id1 = getId(board[i][j]) + 1;
				int id2 = getId(board[i][j + 1]) + 1;
				grid[id1][id2] = grid[id2][id1] = true;
			}
		}
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m; ++j) {
                int id1 = getId(board[i][j]) + 1;
                int id2 = getId(board[i + 1][j]) + 1;
                grid[id1][id2] = grid[id2][id1] = true;
            }
        }
		for (int i = 1; i <= 62; ++i) {
			for (int j = 1; j <= 62; ++j) {
                if (i == j) continue;
				if (grid[i][j]) {
					AddEdge(i << 1 | 1, j << 1, inf);
					AddEdge(j << 1 | 1, i << 1, inf);
				}
			}
        }

		int s = 0, t = 1, N = 62 * 2 + 2;
        memset(up, false, sizeof up);
        memset(down, false, sizeof down);
		for (int i = 0; i < m; ++i) {
			up[getId(board[0][i])] = true;
			down[getId(board[n - 1][i])] = true;
		}
		for (int i = 0; i < 62; ++i) {
			if (up[i])
				AddEdge((i + 1) << 1 | 1, t, inf);
			if (down[i])
				AddEdge(s, (i + 1) << 1, inf);
		}
		return SAP(s, t, N);
	}
};

// CUT begin
ifstream data("ConnectingGameDiv2.sample");

string next_line() {
	string s;
	getline(data, s);
	return s;
}

template <typename T> void from_stream(T &t) {
	stringstream ss(next_line());
	ss >> t;
}

void from_stream(string &s) {
	s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
	int len;
	from_stream(len);
	ts.clear();
	for (int i = 0; i < len; ++i) {
		T t;
		from_stream(t);
		ts.push_back(t);
	}
}

template <typename T>
string to_string(T t) {
	stringstream s;
	s << t;
	return s.str();
}

string to_string(string t) {
	return "\"" + t + "\"";
}

bool do_test(vector<string> board, int __expected) {
	time_t startClock = clock();
	ConnectingGameDiv2 *instance = new ConnectingGameDiv2();
	int __result = instance->getmin(board);
	double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
	delete instance;

	if (__result == __expected) {
		cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
		return true;
	} else {
		cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
		cout << "           Expected: " << to_string(__expected) << endl;
		cout << "           Received: " << to_string(__result) << endl;
		return false;
	}
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
	int cases = 0, passed = 0;
	while (true) {
		if (next_line().find("--") != 0)
			break;
		vector<string> board;
		from_stream(board);
		next_line();
		int __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if ( do_test(board, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1414098657;
		double PT = T / 60.0, TT = 75.0;
		cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
		cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	set<int> cases;
	bool mainProcess = true;
	for (int i = 1; i < argc; ++i) {
		if ( string(argv[i]) == "-") {
			mainProcess = false;
		} else {
			cases.insert(atoi(argv[i]));
		}
	}
	if (mainProcess) {
		cout << "ConnectingGameDiv2 (1000 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
