#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

struct heap{
	int a[100000 + 5] = {0};
	int cnt = 0;
	bool flag = 0;//false表示小根堆，true表示大根堆
	
	bool cmp(int x,int y){//如果x优先级在y之上，返回true
		if (!flag) 
			return x<y;//小根堆
		else
			return x>y;//大根堆
	}
	
	int size(){
		return cnt;
	}
	
	int top(){
		return a[1];
	}
	
	int push(int x){
		a[++cnt] = x;
		int i = cnt;
		while (i>1){
			if (cmp(a[i],a[i/2])){
				swap(a[i],a[i/2]);
				i = i/2;
			}
			else break;
		}
	}
	
	int pop(){
		a[1] = a[cnt--];
		int i = 1,j;
		while (i*2<=cnt){
			j = i*2;
			if (j+1<=cnt && cmp(a[j+1],a[j]))
				j = j+1;
			if ( cmp(a[j],a[i]) ){
				swap(a[j],a[i]);
				i = j;
			} 
			else break;
		}
	}
};

//heap h;
priority_queue <int, vector<int>, greater<int>   > h;

int main(){
	int n,x;
	//h.flag = 1;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&x),h.push(x);
	for (int i=1;i<=n;i++)
		printf("%3d",h.top()), h.pop();
	return 0;
}
//以上的堆都是手写堆，C++的自带库里有模板堆。 
