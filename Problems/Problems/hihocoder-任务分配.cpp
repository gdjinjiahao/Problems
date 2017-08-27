/*
描述
给定 N 项任务的起至时间( S1, E1 ), ( S2, E2 ), ..., ( SN, EN )， 计算最少需要多少台机器才能按时完成所有任务。

同一时间一台机器上最多进行一项任务，并且一项任务必须从头到尾保持在一台机器上进行。任务切换不需要时间。

输入
第一行一个整数 N，(1 ≤ N ≤ 100000)，表示任务的数目。 以下 N 行每行两个整数 Si, Ei，(0 ≤ Si < Ei ≤ 1000000000)，表示任务的起至时间。

输出
输出一个整数，表示最少的机器数目。

样例输入
5
1 10
2 7
6 9
3 4
7 10
样例输出
3
分析：开始时间排序，单调队列
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int n;
pair<long long,long long> task[100010];
priority_queue<long long,vector<long long>,greater<long long> > q;

bool cmp(pair<long long,long long> a,pair<long long,long long> b)
{
	return a.first<b.first;
}



int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld%lld",&task[i].first,&task[i].second);
	sort(task,task+n,cmp);
	int ans=0;
	for(int i=0;i<n;i++){
		int t=task[i].first;
		while(!q.empty()&&q.top()<=t) q.pop();
		q.push(task[i].second);
		ans=max(ans,(int)q.size());
	}
	printf("%d\n",ans);

	
    return 0;
}