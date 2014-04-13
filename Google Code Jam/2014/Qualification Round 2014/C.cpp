#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1};
const char imp[] = "Impossible";
char mine[51][51];
int w[51][51];
bool visited[51][51];
int T, M, R, C;

void dfs(int i, int j) {
	if (visited[i][j]) return;
	visited[i][j] = true;
	if (w[i][j] > 0) return;
	for (int k = 0; k < 8; ++k) {
		if (0 <= i + dx[k] && i + dx[k] < R && 0 <= j + dy[k] && j + dy[k] < C)
			dfs(i + dx[k], j + dy[k]);
	}
}
bool check() {
	int cnt = 0;
	memset(w, 0, sizeof(w));
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (mine[i][j] == '*') {
				w[i][j] = 10;
				cnt ++;	
				for (int k = 0; k < 8; ++k) {
					if (0 <= i + dx[k] && i + dx[k] < R && 0 <= j + dy[k] && j + dy[k] < C)
						w[i + dx[k]][j + dy[k]] = std::min(10, w[i + dx[k]][j + dy[k]] + 1);
				}
			}
		}
	}
	if (cnt != M) {
		std::cerr << R << " " << C << " " << M << std::endl;
		std::cerr << "Not Equal" << std::endl;
		return false;
	}
	memset(visited, false, sizeof(visited));
	dfs(0, 0);
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			if (mine[i][j] != '*' && !visited[i][j])
				return false;
	return true;
}
void print() {
    for (int i = 0; i < R; ++i) printf("%s\n", mine[i]);
}
void perr() {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) std::cerr << w[i][j] << " ";
		std::cerr << std::endl;
	}
	std::cerr << std::endl;
}
void solve() {
    std::cin >> R >> C >> M;
    memset(mine, '*', sizeof(mine));
    for (int i = 0; i < R; ++i)
        mine[i][C] = '\0';
    int B = R * C - M;
    if (B == 1) {
        mine[0][0] = 'c';
        print();
        return;
    }
    if (R == 1 || C == 1) {
        if (R == 1)
            for (int j = 0; j < B; ++j)
                mine[0][j] = '.';
        if (C == 1)
            for (int i = 0; i < B; ++i)
                mine[i][0] = '.';
        mine[0][0] = 'c';
        print();
        if(!check()) perr();
        return;
    }
    if (R == 2 || C == 2) {
        if ((B & 1) || B <= 3) {
            printf("%s\n", imp);
            return;
        }

        if (R == 2) {
            for (int j = 0; j < B / 2; ++j)
                mine[0][j] = mine[1][j] = '.';
        }
        if (C == 2) {
            for (int i = 0; i < B / 2; ++i)
                mine[i][0] = mine[i][1] = '.';
        }
        mine[0][0] = 'c';
        print();
        if(!check()) perr();
        return;
    }
    if (B == 2 || B == 3 || B == 5 || B == 7) {
        printf("%s\n", imp);
        return;
    }
    if (R < 3 || C < 3) std::cerr << "here" << std::endl;
    mine[0][0] = 'c';
    mine[0][1] = mine[1][0] = mine[1][1] = '.';
    if (B == 4) {        
        print();
        if(!check()) perr();
        return;
    }
    mine[0][2] = mine[1][2] = '.';
    if (B == 6) {
        print();
        if(!check()) perr();
        return;
    }
    mine[2][0] = mine[2][1] = '.';
    if (B == 8) {
        print();
        if(!check()) perr();
        return;
    }
    B -= 8;
    for (int j = 3; j < C; ++j) {
    	if (B < 2) break;
    	mine[0][j] = mine[1][j] = '.';
    	B -= 2;    	
    }

    int r = 3;
    while (B >= C) {
    	if (r < R) mine[r][0] = mine[r][1] = '.', B -= 2;
    	for (int j = 2; j < C; ++j) mine[r-1][j] = '.';
    	B -= C - 2, r ++;
    }
    if (B == 1) {
    	mine[r-1][2] = '.';
    	B -= 1;
    }
    if (B >= 2) {
    	if (r < R) mine[r][0] = mine[r][1] = '.', B -= 2;
    	for (int j = 2; j < B + 2; ++j) mine[r-1][j] = '.';
    }
	print();
	if(!check()) perr();
}
int main() {
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    freopen("err", "w", stderr);
    std::cin >> T;
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d:\n", i);
        solve();
    }
    return 0;
}
