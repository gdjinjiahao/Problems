/*
描述
Little Hi has a box which consists of 2xN cells as illustrated below.

+----+----+----+----+----+----+
| A1 | A2 | A3 | A4 | .. | AN |
+----+----+----+----+----+----+
| B1 | B2 | B3 | B4 | .. | BN |
+----+----+----+----+----+----+
There are some coins in each cell. For the first row the amounts of coins are A1, A2, ... AN and for the second row the amounts are B1, B2, ... BN.

Each second Little Hi can pick one coin from a cell and put it into an adjacent cell. (Two cells are adjacent if they share a common side. For example, A1 and A2 are adjacent; A1 and B1 are adjacent; A1 and B2 are not adjacent.)

Now Little Hi wants that each cell has equal number of coins by moving the coins. He wants to know the minimum number of seconds he needs to accomplish it.  

输入
The first line contains an integer, N. 2 <= N <= 100000  

Then follows N lines. Each line contains 2 integers Ai and Bi. (0 <= Ai, Bi <= 2000000000)  

It is guaranteed that the total amount of coins in the box is no more than 2000000000 and is a multiple of 2N.

输出
The minimum number of seconds.

样例输入
2
3 4
6 7
样例输出
4
分析：递推，从左到右一列一列分配，多退少补，退补的位置分情况讨论。
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

long long f[2][100010]={0};

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	long long v=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",f[0]+i,f[1]+i);
		v+=f[0][i]+f[1][i];
	}
	v/=2*n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(f[0][i]>=v&&f[1][i]>=v){
			f[0][i+1]+=f[0][i]-v;
			f[1][i+1]+=f[1][i]-v;
			ans+=f[0][i]-v+f[1][i]-v;
		}
		else if(f[0][i]>=v){
			long long t=f[0][i]-v;
			long long u=v-f[1][i];
			if(t>=u){
				f[0][i+1]+=t-u;
				ans+=t;
			}
			else{
				ans+=u;
				f[1][i+1]-=u-t;
			}
		}
		else if(f[1][i]>=v){
			long long t=f[1][i]-v;
			long long u=v-f[0][i];
			if(t>=u){
				ans+=t;
				f[1][i+1]+=t-u;
			}
			else{
				ans+=u;
				f[0][i+1]-=u-t;
			}
		}
		else{
			long long t=v-f[0][i];
			long long u=v-f[1][i];
			ans+=t+u;
			f[0][i+1]-=t;
			f[1][i+1]-=u;
		}
	}
	printf("%lld\n",ans);
    return 0;
}