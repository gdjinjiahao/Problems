/*
����
����һ������ΪN������A=[A1, A2, ... AN]����֪����ÿ��Ԫ��Ai��ֵ��ֻ������1, 2����3��

������ж����±���Ԫ��(i, j, k)����1 �� i < j < k �� N��Ai < Aj < Ak��  

����
��һ�а���һ������N  

�ڶ��а���N������A1, A2, ... AN��(1 �� Ai �� 3)  

����30%�����ݣ�1 �� N �� 100  

����80%�����ݣ�1 �� N �� 1000  

����100%�����ݣ�1 �� N �� 100000  

���
һ��������ʾ��

��������
6
1 3 2 1 2 3
�������
3
�������������
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