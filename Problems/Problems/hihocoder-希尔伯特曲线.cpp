/*
描述
希尔伯特曲线是以下一系列分形曲线 Hn 的极限。我们可以把 Hn 看作一条覆盖 2n × 2n 方格矩阵的曲线，曲线上一共有 2n × 2n 个顶点(包括左下角起点和右下角终点)，恰好覆盖每个方格一次。

图片：http://hihocoder.com/contest/hiho163/problem/1

Hn(n > 1)可以通过如下方法构造：

1. 将 Hn-1 顺时针旋转90度放在左下角

2. 将 Hn-1 逆时针旋转90度放在右下角

3. 将2个 Hn-1 分别放在左上角和右上角

4. 用3条单位线段把4部分连接起来

对于 Hn 上每一个顶点 p ，我们定义 p 的坐标是它覆盖的小方格在矩阵中的坐标，定义 p 的序号是它在曲线上从起点开始数第几个顶点。给定 p 的坐标，你能算出 p 的序号吗？ 

输入
输入包含3个整数 n , x , y 。 n 是分形曲线的阶数，(x, y)是 p 的坐标。

1 ≤ n ≤ 30

1 ≤ x, y ≤ 2n

输出
p 的序号。

样例输入
3 6 1
样例输出
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