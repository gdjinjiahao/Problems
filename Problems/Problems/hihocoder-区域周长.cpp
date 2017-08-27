/*
描述
给定一个包含 N × M 个单位正方形的矩阵，矩阵中每个正方形上都写有一个数字。

对于两个单位正方形 a 和 b ，如果 a 和 b 有一条共同的边，并且它们的数字相等，那么 a 和 b 是相连的。

相连还具有传递性，如果 a 和 b 相连，b 和 c 相连，那么 a 和 c 也相连。

给定一个单位正方形 s，s 和与 s 相连的所有单位正方形会组成一个区域 R 。小Hi想知道 R 的周长是多少？

输入
第一行包含4个整数 N , M ，x 和 y ， N 和 M 是矩阵的大小， x 和 y 是给定的单位正方形 s 的坐标。(1 ≤ N , M ≤ 100, 0 ≤ x < N , 0 ≤ y < M )

以下是一个 N × M 的矩阵 A，Aij 表示相应的正方形上的数字。(0 ≤ Aij ≤ 100)

输出
输出一个整数表示 R 的周长。

样例输入
6 5 2 1
0 0 1 2 2
3 1 1 3 7
4 3 1 3 7
4 3 0 3 2
4 3 3 0 1
4 5 5 5 5
样例输出
10
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

int f[110][110],v;
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int x,int y)
{
	f[x][y]=-2;
	for(int i=0;i<4;i++){
		int tx=x+d[i][0],ty=y+d[i][1];
		if(f[tx][ty]==v)
			dfs(tx,ty);
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	memset(f,-1,sizeof(f));
	int n,m,x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) scanf("%d",&f[i][j]);

	
	v=f[x+1][y+1];
	dfs(x+1,y+1);
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) if(f[i][j]==-2){
			for(int k=0;k<4;k++){
				int tx=i+d[k][0],ty=j+d[k][1];
				if(f[tx][ty]!=-2) ans++;
			}
		}
	printf("%d\n",ans);
    return 0;
}