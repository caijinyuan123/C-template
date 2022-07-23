#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 1e5 + 10;
int a[MAXN];
int n,k;

bool check(int x){
	long long sum = 0;
	for (int i=1;i<=n;i++)
		sum += a[i]/x;
	if (sum < k)	return false;
	else			return true;
}

int main(){
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	//初始化和读入
	
	int l = 1, r = 1e9 + 10;
	while (l<r) {
		int mid = (l+r+1) / 2;
		if (check(mid)) 
			l = mid;
		else
			r = mid-1;
	}
	if (check(l)) printf("%d",l);
	else printf("0");
	
	//二分
	//check函数的实现
	return 0;
}
