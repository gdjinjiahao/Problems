/*
描述
对于一个01字符串，你每次可以将一个0修改成1，或者将一个1修改成0。那么，你最少需要修改多少次才能把一个01串 S 变为有序01字符串(有序01字符串是指满足所有0在所有1之前的01串)呢？

输入
第一行是一个整数 T，代表测试数据的组数。(1 ≤ T ≤ 10)

以下T行每行包含一个01串 S 。(1 ≤ |S| ≤ 1000)

输出
对于每组测试数据输出最少需要修改的次数。

样例输入
3
000111
010001
100000 
样例输出
0
1
1
分析：
枚举每个位置，将该位置前所有位置0，之后的所有位置1，记录每一位左边有多少1，右边有多少0即可
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