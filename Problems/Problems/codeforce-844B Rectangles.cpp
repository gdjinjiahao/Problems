/*
You are given n × m table. Each cell of the table is colored white or black. Find the number of non-empty sets of cells such that:

1.All cells in a set have the same color.
2.Every two cells in a set share row or column.

Input
The first line of input contains integers n and m (1 ≤ n, m ≤ 50) — the number of rows and the number of columns correspondingly.

The next n lines of input contain descriptions of rows. There are m integers, separated by spaces, in each line. The number equals 0 if the corresponding cell is colored white and equals 1 if the corresponding cell is colored black.

Output
Output single integer  — the number of non-empty sets from the problem description.

分析：
统计每行每列0，1的数量，然后分别计算集合数，例如，n个1可以组成2^n个集合，除去空集，这里注意单个元素组成的集合会被所在行和所在列都加一次，
故初始时刻ans=m*n，先把单个元素的集合数计算出来，之后每行每列计算集合数的公式（以1为例，n个1）位2^n-n-1。
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

long long r[2][55],c[2][55];

int main()
{
	//freopen("in.txt","r",stdin);
	memset(r,0,sizeof(r));
	memset(c,0,sizeof(c));
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			int t;
			cin>>t;
			r[t][i]++;
			c[t][j]++;
		}
	long long ans=n*m;
	for(int i=0;i<n;i++){
		ans+=(1LL<<r[0][i])-r[0][i]-1;
		ans+=(1LL<<r[1][i])-r[1][i]-1;
	}
	for(int i=0;i<m;i++){
		ans+=(1LL<<c[0][i])-c[0][i]-1;
		ans+=(1LL<<c[1][i])-c[1][i]-1;
	}
	cout<<ans<<endl;
	
    return 0;
}