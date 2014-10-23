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

vector<pair<int, int> > adj[2005];
class LonglongestPathTree {
    public:
    long long len;
    int a, b, o;
    void dfs(int u, int p, long long l) {
        if (len < l) {
            len = l;
            o = u;
        }
        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i].first;
            if (v == p || (a == u && b == v) || (a == v && b == u)) continue;
            dfs(v, u, l + adj[u][i].second);
        }
    }
    long long getLength(vector<int> A, vector<int> B, vector<int> L) {
        for (int i = 0; i <= (int)A.size() + 1; ++i) adj[i].clear();
        for (int i = 0; i < (int)A.size(); ++i) {
            adj[A[i]].push_back(make_pair(B[i], L[i]));
            adj[B[i]].push_back(make_pair(A[i], L[i]));
        }
        long long ans = 0;
        for (int i = 0; i < (int)A.size(); ++i) {
            long long now = L[i];
            a = A[i], b = B[i];

            o = a, len = 0;
            dfs(a, a, 0);
            len = 0;
            dfs(o, o, 0);
            now += len;
            
            o = b, len = 0;
            dfs(b, b, 0);
            len = 0;
            dfs(o, o, 0);
            now += len;
            ans = max(ans, now);
        }
        return ans;
    }
};

// CUT begin
ifstream data("LonglongestPathTree.sample");

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

bool do_test(vector<int> A, vector<int> B, vector<int> L, long long __expected) {
    time_t startClock = clock();
    LonglongestPathTree *instance = new LonglongestPathTree();
    long long __result = instance->getLength(A, B, L);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
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
        vector<int> A;
        from_stream(A);
        vector<int> B;
        from_stream(B);
        vector<int> L;
        from_stream(L);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(A, B, L, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1412811411;
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
        cout << "LonglongestPathTree (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
