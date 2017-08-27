/*
描述
H国的身份证号码是一个N位的正整数(首位不能是0)。此外，由于防伪需要，一个N位正整数是合法的身份证号码当且仅当每位数字都小于等于K，并且任意相邻两位数字的乘积也小于等于K。

例如对于K=5, 101、211、210等都是合法的号码，而106、123、421等都是非法的号码。

给定一个正整数N以及K，请从小到大输出所有合法的号码。  

输入
两个整数N和K。

对于80%的数据，1 ≤ N ≤ 6。

对于100%的数据，1 ≤ N ≤ 9，1 ≤ K ≤ 5。

输出
按从小到大的顺序输出所有合法的N位号码，每个号码占一行。

样例输入
2 4
样例输出
10  
11  
12  
13  
14  
20  
21  
22  
30  
31  
40  
41
分析：dfs暴力即可
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
int n,k;

void dfs(int d,int id)
{
	if(id==n){
		printf("%d\n",d);
		return ;
	}
	int pre=d%10;
	d=d*10;
	int t=0;
	while(t<=k&&t*pre<=k){
		dfs(d+t,id+1);
		t++;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	
	cin>>n>>k;

	for(int i=1;i<=k;i++)
		dfs(i,1);

    return 0;
}