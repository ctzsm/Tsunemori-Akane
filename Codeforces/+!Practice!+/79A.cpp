#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int x,y;
int pre[12];
int main(int argc, char** argv) {
	scanf("%d%d",&x,&y);
	int who = 0;
	while(true){
		bool flag = false;
		if(who){
			for(int i = 22;i >= 2; --i){
				int t = 220 - i * 10;
				if(t % 100 == 0){
					if(y >= i && x >= t / 100){
						y -= i,x -= t / 100;
						flag = true;
						break;
					}
				}
			}
		}else{
			for(int i = 2;i >= 0; --i){
				int t = 220 - i * 100;
				if(y >= t / 10 && x >= i){
					y -= t / 10,x -= i;
					flag = true;
					break;
				}
			}
		}
		who = 1 - who;
		if(!flag) break;
	}
	if(who) puts("Hanako");
	else puts("Ciel");
	return 0;
}

