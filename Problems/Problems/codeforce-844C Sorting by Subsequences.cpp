/*
题意：给定n个不同数字，尽可能分成多的子序列，使得每个子序列排序后（子序列，不用保证连续，子序列排序其他数字位置不变），整个序列有序。
输出最多可以分成几个序列，并输出每个序列的长度和元素对应的索引号。
分析：
设原序列为a，a元素排序后的序列为b
a不论怎么划分，最终排序完都是b，故a中每个元素的最终位置是确定的
对于每组划分，先找到a中一个还没有被分组的元素a[i]，找到在b中的位置j，该位置最终需要放a[i]，但j位置放置的不是a[i]是a[j]，故需要再找到a[j]在b
中的位置，这样必然会形成一个回路，这个回路就是划分好的一组。
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <bitset>
using namespace std;

int e[100010],e1[100010];
bool vis[100010];
map<int,int> m;
vector<int> p[100010];

int main()
{
	//freopen("in.txt","r",stdin);
	//vis[i]表示第i个数字有没有被分组
	memset(vis,false,sizeof(vis));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",e+i);
		e1[i]=e[i];
		p[i].clear();
	}
	sort(e1+1,e1+n+1);
	for(int i=1;i<=n;i++) m[e1[i]]=i;
	int k=0;
	for(int i=1;i<=n;i++) if(!vis[i]){
		int t=i;
		//寻找回路
		do{
			vis[t]=true;
			p[k].push_back(t);
			t=m[e[t]];
		}while(t!=i);
		k++;
	}
	printf("%d\n",k);
	for(int i=0;i<k;i++){
		printf("%d",p[i].size());
		sort(p[i].begin(),p[i].end());
		for(int j=0;j<p[i].size();j++){
			printf(" %d",p[i][j]);
		}
		printf("\n");
	}
    return 0;
}