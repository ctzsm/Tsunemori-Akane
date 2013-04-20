#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

int T, nCase = 1;
int N, M;
int a[105][105];
int col[105], row[105];
bool solve(){
    memset(col, 0, sizeof(col));
    memset(row, 0, sizeof(row));
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            scanf("%d", &a[i][j]);
            col[j] = max(col[j], a[i][j]);
            row[i] = max(row[i], a[i][j]);
        }
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j)
            if(!(a[i][j] == row[i] || a[i][j] == col[j])) return false;
    }
    return true;
}
int main(int argc, char** argv) {
    freopen("B-large-practice.in", "r", stdin);
    freopen("B-large-practice.out", "w", stdout);
    scanf("%d", &T);
    while(nCase <= T){
        printf("Case #%d: ", nCase++);
        printf(solve() ? "YES\n" : "NO\n");
    }
    return 0;
}
