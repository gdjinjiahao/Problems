/*
����
H�������֤������һ��Nλ��������(��λ������0)�����⣬���ڷ�α��Ҫ��һ��Nλ�������ǺϷ������֤���뵱�ҽ���ÿλ���ֶ�С�ڵ���K����������������λ���ֵĳ˻�ҲС�ڵ���K��

�������K=5, 101��211��210�ȶ��ǺϷ��ĺ��룬��106��123��421�ȶ��ǷǷ��ĺ��롣

����һ��������N�Լ�K�����С����������кϷ��ĺ��롣  

����
��������N��K��

����80%�����ݣ�1 �� N �� 6��

����100%�����ݣ�1 �� N �� 9��1 �� K �� 5��

���
����С�����˳��������кϷ���Nλ���룬ÿ������ռһ�С�

��������
2 4
�������
10  
11  
12  
13  
14  
20  
21  
22  
30  
31  
40  
41
������dfs��������
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
int n,k;

void dfs(int d,int id)
{
	if(id==n){
		printf("%d\n",d);
		return ;
	}
	int pre=d%10;
	d=d*10;
	int t=0;
	while(t<=k&&t*pre<=k){
		dfs(d+t,id+1);
		t++;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	
	cin>>n>>k;

	for(int i=1;i<=k;i++)
		dfs(i,1);

    return 0;
}