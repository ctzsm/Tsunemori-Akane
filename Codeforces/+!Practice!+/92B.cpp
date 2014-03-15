#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

char t[1000005],s[2000005];
int len;
void add(int i){
	while(s[i] == '1'){
		s[i] = '0';
		i++;
	}
	s[i++] = '1';
	len = max(len,i);
}
int main(int argc, char** argv) {
	scanf("%s",t);
	len = strlen(t);
	int ans = 0,pos = 0;
	memset(s,'0',sizeof(s));
	for(int i = 0;i < len; ++i) s[len - i - 1] = t[i];
	while(true){
		if(pos == len - 1 && s[pos] == '1') break;
		if(s[pos] == '1'){
			add(pos);
		}else{
			pos++;
		}
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}

