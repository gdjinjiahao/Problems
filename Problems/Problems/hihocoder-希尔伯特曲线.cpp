/*
����
ϣ����������������һϵ�з������� Hn �ļ��ޡ����ǿ��԰� Hn ����һ������ 2n �� 2n �����������ߣ�������һ���� 2n �� 2n ������(�������½��������½��յ�)��ǡ�ø���ÿ������һ�Ρ�

ͼƬ��http://hihocoder.com/contest/hiho163/problem/1

Hn(n > 1)����ͨ�����·������죺

1. �� Hn-1 ˳ʱ����ת90�ȷ������½�

2. �� Hn-1 ��ʱ����ת90�ȷ������½�

3. ��2�� Hn-1 �ֱ�������ϽǺ����Ͻ�

4. ��3����λ�߶ΰ�4������������

���� Hn ��ÿһ������ p �����Ƕ��� p �������������ǵ�С�����ھ����е����꣬���� p ����������������ϴ���㿪ʼ���ڼ������㡣���� p �����꣬������� p ������� 

����
�������3������ n , x , y �� n �Ƿ������ߵĽ�����(x, y)�� p �����ꡣ

1 �� n �� 30

1 �� x, y �� 2n

���
p ����š�

��������
3 6 1
�������
60
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	long long n,x,y,ans=0,t;

	scanf("%lld%lld%lld",&n,&x,&y);

	while(n>1){
		long long tx=1L<<(n-1),ty=1L<<(n-1);
		if(x>tx&&y>ty){
			ans+=2*(1L<<(2*n-2));
			x-=1L<<(n-1);
			y-=1L<<(n-1);
		}
		else if(x>tx&&y<=ty){
			ans+=3*(1L<<(2*n-2));
			t=(1L<<n)+1-x;
			x=(1L<<(n-1))+1-y;
			y=t;
		}
		else if(x<=tx&&y>ty){
			ans+=1L<<(2*n-2);
			y-=1L<<(n-1);
		}
		else{
			t=x;
			x=y;
			y=t;
		}
		n--;
	}
	if(x==1&&y==1) ans+=1;
	else if(x==1&&y==2) ans+=2;
	else if(x==2&&y==2) ans+=3;
	else ans+=4;

	printf("%lld\n",ans);
    return 0;
}