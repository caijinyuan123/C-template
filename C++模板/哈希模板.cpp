#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int MR=1e6+10;
const int P=257;
const LL MOD=1e9+9;

int n;
LL hashValue[MR];
char s[MR];

LL makeHash()
{
    LL h=0;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        h=h*P+s[i];
        h%=MOD;
    }
    return h;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        hashValue[i]=makeHash();
    }
    sort(hashValue+1,hashValue+1+n);
    int cnt=1;
    for(int i=2;i<=n;i++)
    {
        if(hashValue[i]!=hashValue[i-1])
        {
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
