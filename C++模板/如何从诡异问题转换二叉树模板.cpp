#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int f[MAXN];//f[i]存储i号节点的父亲
int h[MAXN];//h[i]存储i号节点的深度
int l[MAXN],r[MAXN];//l[i],r[i]存储i号节点的左右儿子
int g[MAXN][4];	//g[i][j]存储i号节点第j个连接点的位置
bool used[MAXN];
int num[MAXN];//num[i]存储第i层的宽度
int root;//root存储二叉树的根节点
int n,ans;


void dfs(int x){//求从根到x的深度
	if (x==0) return;		//对根特判
	if (h[x]!=0)	return;	//记忆化搜索
	dfs(f[x]);				//先求父亲的深度
	h[x] = h[ f[x] ]+1;
}

bool build(int x){
	if (used[x]||x==0)	return false;//记忆化
	used[x] = true;
	bool left = false;
	for (int i=1;i<=g[x][0];i++){
		int y = g[x][i];
		if (build(y) ){
			if (!left){	//找到左儿子
				l[x] = y;
				f[y] = x;
				left = true;
			}
			else {		//找到右儿子
				r[x] = y;
				f[y] = x;
			}
		}
	}
		
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x][ ++g[x][0] ] = y;
		g[y][ ++g[y][0] ] = x;
	}
	root = 1;
	build(1);
	f[0] = 0;
	int depth = 0,width = 0;//宽度，深度
	for (int i=1;i<=n;i++) {
		dfs(i);
		num[ h[i] ]++;
		depth = max(depth,h[i]);
		width = max(width, num[ h[i] ]);
	}		
	int cnt = 0;//计算距离
	int u,v;
	scanf("%d%d",&u,&v);
	while (u!=v){
		if ( h[u]>h[v] )
			u = f[u];
		else
			v = f[v];
		cnt++;
	}
	printf("%d\n%d\n%d",depth,width,cnt);
	
}
