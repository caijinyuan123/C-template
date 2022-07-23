#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
const int MAXN=1e5+10;
string t;
char s[MAXN];	//s[i]记录第i个字符的值
int nxt[MAXN];	//nxt[i]记录第i个字符的下一个位置
int cur=0,cnt=0,last=0;
int main(){
    while(cin >> t){
        memset(nxt,0,sizeof(nxt));
        for(int i=0;i<t.size();i++){
            if(t[i]=='['){
                cur=0;
            }
            else if(t[i]==']'){
                cur=last;
            }
            else{
                cnt++;
                s[cnt]=t[i];
                nxt[cnt]=nxt[cur];
                nxt[cur]=cnt;
                cur=cnt;
                if(nxt[cnt]==0) last=cnt;
            }
        }
        for(int i=nxt[0];i!=0;i=nxt[i]){
            printf("%c",s[i]);
        }
        printf("\n");
        break;
    }

    return 0;
}
//链表没有具体模板，我就用了我一道很模板的题做模板 
