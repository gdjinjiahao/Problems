/*
����
����һ��01�ַ�������ÿ�ο��Խ�һ��0�޸ĳ�1�����߽�һ��1�޸ĳ�0����ô����������Ҫ�޸Ķ��ٴβ��ܰ�һ��01�� S ��Ϊ����01�ַ���(����01�ַ�����ָ��������0������1֮ǰ��01��)�أ�

����
��һ����һ������ T������������ݵ�������(1 �� T �� 10)

����T��ÿ�а���һ��01�� S ��(1 �� |S| �� 1000)

���
����ÿ������������������Ҫ�޸ĵĴ�����

��������
3
000111
010001
100000 
�������
0
1
1
������
ö��ÿ��λ�ã�����λ��ǰ����λ��0��֮�������λ��1����¼ÿһλ����ж���1���ұ��ж���0����
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
using namespace std;

char t[1010];
int t0[1010],t1[1010];
int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);getchar();


	while(n--){
		char temp;
		int len=1;
		while((temp=getchar())!='\n') t[len++]=temp;
		t1[0]=0;t0[len]=0;
		for(int i=1;i<len;i++)
			t1[i]=t1[i-1]+t[i]-'0';
		for(int i=len-1;i>=1;i--)
			t0[i]=t0[i+1]+1-t[i]+'0';
		int ans=1000;
		for(int i=1;i<len;i++)
			ans=min(ans,t1[i-1]+t0[i+1]);
		printf("%d\n",ans);
	}
    return 0;
}