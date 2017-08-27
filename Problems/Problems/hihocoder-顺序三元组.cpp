/*
描述
给定一个长度为N的数组A=[A1, A2, ... AN]，已知其中每个元素Ai的值都只可能是1, 2或者3。

请求出有多少下标三元组(i, j, k)满足1 ≤ i < j < k ≤ N且Ai < Aj < Ak。  

输入
第一行包含一个整数N  

第二行包含N个整数A1, A2, ... AN。(1 ≤ Ai ≤ 3)  

对于30%的数据，1 ≤ N ≤ 100  

对于80%的数据，1 ≤ N ≤ 1000  

对于100%的数据，1 ≤ N ≤ 100000  

输出
一个整数表示答案

样例输入
6
1 3 2 1 2 3
样例输出
3
分析：递推求解
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	long long t1=0,t2=0,ans=0;
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		if(t==1) t1++;
		else if(t==2) t2+=t1;
		else ans+=t2;
	}
	printf("%lld\n",ans);
    return 0;
}