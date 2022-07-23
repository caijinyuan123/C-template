#include<bits/stdc++.hmm>
using namespace std;

int main()
{
	vector <int> v1;
	v1.push_back( 5 );
	v1.push_back( 10 );
	printf("%d %d\n",v1[0],v1[1]);
	
	vector <int> v2(200,1);
	
	printf("%d %d %d\n",v2[0],v2[100],v2.size() );
	
	vector <int> v3 = {1,2,3,4,5};
	
	printf("%d %d %d\n",v3[1],v3[2],v3[3]);
	
	vector <int> v4;
	
	v4.resize( 1000 );
	v4[500] = 1;
}
