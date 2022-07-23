#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 1e3 + 10;
int w[MAXN];//w[i]代表第i个元素的体积
int v[MAXN];//v[i]代表第i个元素的价值
int f[MAXN][MAXN];//f[i][j]代表前i个物品,占用j体积时的最大价值
int n,m;

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&w[i],&v[i]);
	//初始化和读入
	
	f[0][0] = 0;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=m;j++) {
			if (j-w[i]<0)
				f[i][j] = f[i-1][j];
			else
				f[i][j] = max(f[i-1][j] , f[i-1][j-w[i] ] + v[i]);
		}
	//递推计算f[i][j]
	printf("%d",f[n][m]);
	//输出答案
    return 0;
}
