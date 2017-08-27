/*
描述
There are N queens in an infinite chessboard. We say two queens may attack each other if they are in the same vertical line, horizontal line or diagonal line even if there are other queens sitting between them.

Now given the positions of the queens, find out how many pairs may attack each other?

输入
The first line contains an integer N.

Then N lines follow. Each line contains 2 integers Ri and Ci indicating there is a queen in the Ri-th row and Ci-th column.  

No two queens share the same position.  

For 80% of the data, 1 <= N <= 1000

For 100% of the data, 1 <= N <= 100000, 0 <= Ri, Ci <= 1000000000

输出
One integer, the number of pairs may attack each other.

样例输入
5  
1 1  
2 2  
3 3   
1 3
3 1
样例输出
10

分析：
主要是斜边判定
x1-x2=y1-y2 => x1-y1=x2-y2
x1-x2=-(y1-y2) => x1+y1=x2+y2
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

map<int,long long> mx,my,md,mdr;

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	while(n--){
		int x,y;
		scanf("%d%d",&x,&y);
		mx[x]++;
		my[y]++;
		md[x-y]++;
		mdr[x+y]++;
	}
	long long ans=0;

	for(map<int,long long>::iterator ite=mx.begin();ite!=mx.end();ite++) if(ite->second>1)
		ans+=((ite->second)-1)*(ite->second)/2;
	for(map<int,long long>::iterator ite=my.begin();ite!=my.end();ite++) if(ite->second>1)
		ans+=((ite->second)-1)*(ite->second)/2;
	for(map<int,long long>::iterator ite=md.begin();ite!=md.end();ite++) if(ite->second>1)
		ans+=((ite->second)-1)*(ite->second)/2;
	for(map<int,long long>::iterator ite=mdr.begin();ite!=mdr.end();ite++) if(ite->second>1)
		ans+=((ite->second)-1)*(ite->second)/2;
	cout<<ans<<endl;
    return 0;
}