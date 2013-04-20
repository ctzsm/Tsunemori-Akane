#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

int T, nCase = 1;
char board[5][5];
bool check(char c){
    for(int i = 0; i < 4; ++i){
        bool flag = true;
        for(int j = 0; j < 4; ++j){
            if(board[i][j] != c){
                flag = false; break;
            }
        }
        if(flag) return true;
    }
    for(int j = 0; j < 4; ++j){
        bool flag = true;
        for(int i = 0; i < 4; ++i){
            if(board[i][j] != c){
                flag = false; break;
            }
        }
        if(flag) return true;
    }
    bool flag = true;
    for(int i = 0; i < 4; ++i){
        if(board[i][i] != c){
            flag = false; break;
        }
    }
    if(flag) return true;
    flag = true;
    for(int i = 0; i < 4; ++i){
        if(board[i][3 - i] != c){
            flag = false; break;
        }
    }
    return flag;
}
int judge(){
    bool complete = true;
    int tx = -1, ty = -1;
    for(int i = 0; i < 4; ++i) scanf("%s", board[i]);
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if(board[i][j] == '.') complete = false;
            if(board[i][j] == 'T') tx = j, ty = i;
        }
    }
    if(tx != -1) board[ty][tx] = 'X';
    if(check('X')) return 1;
    if(tx != -1) board[ty][tx] = 'O';
    if(check('O')) return 2;
    if(complete) return 0;
    return 3;
}
int main(int argc, char** argv) {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%d", &T);
    while(nCase <= T){
        printf("Case #%d: ", nCase++);
        switch(judge()){
            case 0: puts("Draw"); break;
            case 1: puts("X won"); break;
            case 2: puts("O won"); break;
            case 3: puts("Game has not completed"); break;
        }
    }
    return 0;
}

