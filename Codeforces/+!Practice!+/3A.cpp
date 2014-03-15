#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct node{
	int x,y,step;
	vector<string> ans;
};
int dx[] = {0,0,1,1,1,-1,-1,-1};
int dy[] = {1,-1,0,1,-1,0,1,-1};
string dir[] = {"U","D","R","RU","RD","L","LU","LD"};
char s[3],t[3];
bool chess[10][10];
void bfs(){
	node start,end;
	start.x = s[0] - 'a';
	start.y = (s[1] - '1');
	start.step = 0;
	end.x = t[0] - 'a';
	end.y = (t[1] - '1');
	if(s[0] == t[0] && s[1] == t[1]){
		printf("0\n");
		return;
	}
	chess[start.y][start.x] = true;
	queue<node> q;
	q.push(start);
	int cnt = 0;
	while(!q.empty()){
		node now = q.front();q.pop();
//		printf("%d %d %d\n",now.x,now.y,cnt++);
		for(int i = 0;i < 8; ++i){
			int nowx = now.x + dx[i];
			int nowy = now.y + dy[i];
			int nows = now.step + 1;
			if(nowx >= 0 && nowx < 8 && nowy >= 0 && nowy < 8 && !chess[nowy][nowx]){
				chess[nowy][nowx] = true;
				node topush;
				topush.x = nowx;
				topush.y = nowy;
				topush.step = nows;
				topush.ans = now.ans;
				topush.ans.push_back(dir[i]);
				if(nowx == end.x && nowy == end.y){
					printf("%d\n",topush.step);
					for(int j = 0;j < topush.ans.size(); ++j){
						printf("%s\n",topush.ans[j].c_str());
					}
					return;
				}
				q.push(topush);
			}
		}
	}
}
int main(int argc, char** argv) {
	freopen("in","r",stdin);
	scanf("%s%s",s,t);
	bfs();
	return 0;
}

