#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N,K;
bool seat[105][105];
int dis[105][105];
int dp[105][105][105];
int xc,yc;

void occupy(int M){
	int nowx = 1,nowy = 1,nowv = 1000000000;
	for(int i = 1;i <= K; ++i){
		for(int j = 1;j <= K - M + 1; ++j){
			if(seat[i][j]) continue;
			if(dis[i][j] - j + 1 < M) continue;
			int val = M * abs(xc - i);
			int a = j,b = j + M - 1;
			if(b <= yc){
				b = yc - b;
				val += M * b + M * (M - 1) / 2;
			}else if(a >= yc){
				a = a - yc;
				val += M * a + M * (M - 1) / 2;
			}else{
				a = yc - a;b = b - yc;
				val += (a * (a + 1) + b * (b + 1)) / 2;
			}
			if(val < nowv){
				nowv = val,nowx = i,nowy = j;
			}
		}
	}
	if(nowv == 1000000000){
		printf("-1\n");return;
	}
	for(int i = nowy;i < nowy + M; ++i){
		seat[nowx][i] = true;
	}
	for(int i = 1;i < nowy; ++i){
		dis[nowx][i] = min(nowy - 1,dis[nowx][i]);
	}
	printf("%d %d %d\n",nowx,nowy,nowy + M - 1);
}
int main(int argc, char** argv) {
//	freopen("in","r",stdin);
	scanf("%d%d",&N,&K);
	xc = yc = (K + 1) / 2;
	for(int i = 1;i <= K; ++i) for(int j = 1;j <= K; ++j) dis[i][j] = K;
	for(int i = 0;i < N; ++i){
		int M;scanf("%d",&M);
//		printf("%d ",M);
		occupy(M);
	}
	return 0;
}

