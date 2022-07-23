#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 1e5 + 10;

int f[MAXN];			//f[i]记录i的父亲
int l[MAXN],r[MAXN];	//l[i],r[i]记录i的左右儿子
int root;				//root记录根
int a[MAXN];			//a[i]记录第i个点的值
int n,m=0;
int x;

void insert(int x,int key){	//把key插入到以x为根的二叉查找树中
	int t = (key>a[x]?r[x]:l[x]);
	if (t==0){
		if (key>a[x])
			r[x] = m;
		else
			l[x] = m;
	}
	else 
		insert(t,key);
}


void midTrav(int x){
	if (x==0)	return;
	midTrav(l[x]);
	cout << a[x] << " ";
	midTrav(r[x]);
}
void lastTrav(int x){
	if (x==0)	return;
	lastTrav(l[x]);
	lastTrav(r[x]);
	cout << a[x] << " ";
	
}

int main(){
	cin >> n;
	for (int i=1;i<=n;i++){
		m++;
		cin >> a[m];
		if (m==1){
			root = 1;
			continue;		//对根特判
		}
		else
			insert(root,a[i]);
	}
	
	midTrav(root);
	cout << endl;
	lastTrav(root);
}


//二叉查找树其实是map翻版，俗称二叉查找树 
