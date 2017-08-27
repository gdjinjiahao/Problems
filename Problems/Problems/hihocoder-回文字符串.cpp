/*
描述
给定一个字符串 S ，最少需要几次增删改操作可以把 S 变成一个回文字符串？

一次操作可以在任意位置插入一个字符，或者删除任意一个字符，或者把任意一个字符修改成任意其他字符。

输入
字符串 S。S 的长度不超过100, 只包含'A'-'Z'。

输出
最少的修改次数。

样例输入
ABAD
样例输出
1
分析：
动态规划即可
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[110];
int f[110][110]={0};
int main()
{
    scanf("%s",s);
	int n=strlen(s),r,t,l;
	for(t=2;t<=n;t++) for(l=0;(r=l+t-1)<n;l++){
		f[l][r]=f[l+1][r-1]+(s[l]!=s[r]);
		f[l][r]=min(f[l][r],f[l+1][r]+1);
		f[l][r]=min(f[l][r],f[l][r-1]+1);
	}
	printf("%d\n",f[0][n-1]);
    return 0;
}