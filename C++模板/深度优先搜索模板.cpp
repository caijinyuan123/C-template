#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int a,b;
int flag = 0;
int c[100] ;

bool dfs(int x,int p)   //返回从x是否能到达b
                        //当前是第p次变化
{
    c[p] = x;
    if (x==b) {
        if (flag == 0) {
            flag = 1;
            printf("YES\n%d\n",p);
            for (int i=1;i<=p;i++)
                printf("%d ",c[i]);
            //输出方案;
        }
        return true;
    }
    if (x>b) return false;
    //出口
    return dfs(x*2,p+1) || dfs(x*10 + 1,p+1);
    //递归子问题
}

int main(){
    scanf("%d%d",&a,&b);
    dfs(a,1);
    if (flag == 0) printf("NO");
	return 0;
}
