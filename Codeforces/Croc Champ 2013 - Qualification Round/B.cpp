#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

char s[100005];
int main(int argc, char** argv) {
//    freopen("in", "r", stdin);
    gets(s);
    int n = strlen(s);
    bool leftq = false, left = false;
    for(int i = 0; i < n; ++i){
        if(s[i] == ' '){
            if(leftq){
                putchar(s[i]);
                continue;
            }
            if(left){
                left = false;
                putchar('>');
                putchar('\n');
            }
            continue;
        }
        if(s[i] == '"'){
            if(!leftq){
                leftq = true;
                putchar('<');
            }else{
                leftq = false;
                putchar('>');
                putchar('\n');
            }
            continue;
        }
        if(leftq){
            putchar(s[i]);
            continue;
        }
        if(!left){
            left = true;
            putchar('<');
            putchar(s[i]);
        }else{
            putchar(s[i]);
        }
    }
    if(left) printf(">\n");
    return 0;
}

