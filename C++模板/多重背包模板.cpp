#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 1000 + 10;
const int MR = 2000;

struct node{
	int w;
	int v;
}a[MAXN * 20];	//NlogN

int n,W,m=0;
int s,w,v;
int f[MR];

void divide(int w,int v,int s){
	int k = 1,sum = 0;
	while (k+sum < s){
		m++;
		a[m].w = w * k;
		a[m].v = v * k;
		sum += k;
		k*=2;
	}
	m++;
	a[m].w = w * (s - sum);
	a[m].v = v * (s - sum);	
}

int main(){
	scanf("%d%d",&n,&W);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&w,&v,&s);
		divide(w,v,s);
	}
	
	//有m个等效01背包
	for (int i=1;i<=m;i++)
		for (int j=W;j>=a[i].w;j--)
			f[j] = max(f[j],f[j-a[i].w] + a[i].v);
	
	printf("%d",f[W]);
	
	return 0;
}
