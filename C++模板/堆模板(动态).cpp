#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct heap{
	//int a[100000 + 5] = {0};	
	vector <int> a;	//vector第一个要改的地方
	int cnt = 0;
	bool flag = 0;//true代表大根堆，false代表小根堆
	
	heap(){	//构造函数
		//printf("生成了一个堆！\n");
		a.push_back(0);	//vector第四个要改的地方
	}
	
	bool cmp(int x,int y){
		if (flag)	
			return (x>y);
		else	
			return (x<y);
	}
	
	
	int size(){
		return cnt;
	}
	
	int top(){
		if (cnt>0)	return a[1];
		else return 0;//非法
	}
	
	int push(int x){
		a.push_back(x),cnt++;	//vector第二个要改的地方
		//a[++cnt] = x;
		int i = cnt;
		while (i>1 && cmp(a[i],a[i/2])){
			swap(a[i],a[i/2]);
			i/=2;
		}
	}
	
	int pop(){
		a[1] = a[cnt--];
		a.pop_back();		//vector第三个要改的地方
		int i = 1,j;
		while (i*2<=cnt) {
			j = i*2;
			if (j+1<=cnt && cmp(a[j+1],a[j]))
				j++;
			if (cmp(a[j],a[i])){
				swap(a[i],a[j]);
				i = j;
			}
			else break;
		}
	}
	
};

int n,k,x;

int main(){
	scanf("%d%d",&n,&k);
	heap h;
	h.flag = true;//设为大根堆
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		h.push(x);	//建立堆
	}
	for (int i=1;i<=k;i++){
		x = h.top();
		h.pop();
		h.push(x- x/2);	//取出最大石子后放回一半
	}
	int cnt = 0;
	while (h.size()>0){
		cnt += h.top();
		h.pop();
	}
	printf("%d",cnt);
}
//以上的堆都是手写堆，C++的自带库里有模板堆。 
