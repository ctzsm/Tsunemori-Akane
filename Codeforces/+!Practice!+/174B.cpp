#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

char s[400005];
vector<int> bet;
int len;

int main(int argc, char** argv) {
	freopen("in", "r", stdin);
	scanf("%s", s);
	len = strlen(s);
	int cnt = 0, dot = 0;
	for (int i = 0; i < len; ++i) {
		if(s[i] == '.'){
			dot++;
			if(dot == 1 && (cnt == 0 || cnt > 8)){
				printf("NO\n");return 0;
			}
			if(dot > 1 && (cnt < 2 || cnt > 11)){
				printf("NO\n");return 0;
			}
			bet.push_back(cnt);
			cnt = 0;
		}else{
			cnt++;
		}
	}
	if(cnt == 0 || cnt > 3 || dot == 0){
		printf("NO\n");return 0;
	}
	bet.push_back(cnt);
	printf("YES\n");
	int b = 0;
	for(int i = 0;i < bet[0]; ++i) putchar(s[i]);
	b += bet[0];
	for(int i = 1;i < bet.size() - 1; ++i){
		putchar('.');b ++;
		for(int j = 0;j < bet[i]; ++j){
			putchar(s[b+j]);
			if(bet[i] == 11 && j == 2) putchar('\n');
			if(bet[i] == 10 && j == 1) putchar('\n');
			if(bet[i] <= 9 && j == 0) putchar('\n');
		}
		b += bet[i];
	}
	putchar('.');b ++;
	for(int i = 0;i < bet[bet.size() - 1]; ++i) putchar(s[b+i]);
	return 0;
}

