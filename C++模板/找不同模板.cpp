#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
typedef long long LL;
int a[MAXN],b[MAXN],idA[MAXN],ans;
bool vis[MAXN];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int p=unique(b+1,b+1+n)-b-1;
    //for(int i=1;i<=p;i++) printf("%d ",b[i]);printf("\n");
    for(int i=1;i<=n;i++){
        idA[i]=lower_bound(b+1,b+1+p,a[i])-b;
        //printf("%d ",idA[i]);
    }
    int l=1,r=n;
    memset(vis,0,sizeof(vis));
    while(r>=1 && !vis[idA[r]]){
        vis[idA[r]]=1;
        r--;
    }
    if(r==0){
        printf("0\n");
        return 0;
    }
    ans=r-l+1;
    //随着l的增长，r单调增长，因此可用尺取法
    while(l<r){		//尝试不再删除第l个元素
        if(vis[idA[l]]){		//如果第l个元素原本已出现
            while(r<n && vis[idA[l]]){	//右端需要删到第l个元素消失为止
                r++;
                vis[idA[r]]=0;
            }
        }
        if(r==n && vis[idA[l]]){	//如果r已经尽量靠右仍不能消掉第l个元素，则无解
            break;
        }
        vis[idA[l]]=1;
        l++;
        ans=min(ans,r-l+1);			//更新答案
    }
    printf("%d\n",ans);
    return 0;
}
