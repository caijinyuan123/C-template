#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long LL;
const int INF=1e9; 
const int CQY = 1e3 + 10;
const int CJY = 2e4 + 10;
int H,N;
int a[CQY],b[CQY],c[CQY][CJY];
int main(){
    scanf("%d%d",&H,&N);
    for(int i=1;i<=N;i++)
	scanf("%d%d",&a[i],&b[i]);
    memset(c,0x3f,sizeof(c));
    c[0][0]=0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=CJY-1;j++){
            c[i][j]=c[i-1][j];
            if(j>=a[i]) c[i][j]=min(c[i][j],c[i][j-a[i]]+b[i]);
        }
    }
    int ans=INF;
    for(int j=CJY-1;j>=H;j--){
        ans=min(ans,c[N][j]);
    }
    printf("%d\n",ans);
    return 0;
}
