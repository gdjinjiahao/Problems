/*
����
���� N �����������ʱ��( S1, E1 ), ( S2, E2 ), ..., ( SN, EN )�� ����������Ҫ����̨�������ܰ�ʱ�����������

ͬһʱ��һ̨������������һ�����񣬲���һ����������ͷ��β������һ̨�����Ͻ��С������л�����Ҫʱ�䡣

����
��һ��һ������ N��(1 �� N �� 100000)����ʾ�������Ŀ�� ���� N ��ÿ���������� Si, Ei��(0 �� Si < Ei �� 1000000000)����ʾ���������ʱ�䡣

���
���һ����������ʾ���ٵĻ�����Ŀ��

��������
5
1 10
2 7
6 9
3 4
7 10
�������
3
��������ʼʱ�����򣬵�������
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