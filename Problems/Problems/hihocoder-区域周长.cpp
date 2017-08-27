/*
����
����һ������ N �� M ����λ�����εľ��󣬾�����ÿ���������϶�д��һ�����֡�

����������λ������ a �� b ����� a �� b ��һ����ͬ�ıߣ��������ǵ�������ȣ���ô a �� b �������ġ�

���������д����ԣ���� a �� b ������b �� c ��������ô a �� c Ҳ������

����һ����λ������ s��s ���� s ���������е�λ�����λ����һ������ R ��СHi��֪�� R ���ܳ��Ƕ��٣�

����
��һ�а���4������ N , M ��x �� y �� N �� M �Ǿ���Ĵ�С�� x �� y �Ǹ����ĵ�λ������ s �����ꡣ(1 �� N , M �� 100, 0 �� x < N , 0 �� y < M )

������һ�� N �� M �ľ��� A��Aij ��ʾ��Ӧ���������ϵ����֡�(0 �� Aij �� 100)

���
���һ��������ʾ R ���ܳ���

��������
6 5 2 1
0 0 1 2 2
3 1 1 3 7
4 3 1 3 7
4 3 0 3 2
4 3 3 0 1
4 5 5 5 5
�������
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