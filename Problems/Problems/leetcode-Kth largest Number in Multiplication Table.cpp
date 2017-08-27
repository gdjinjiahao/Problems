/*
本题和codeforce 448相同。用了codeforce的代码。
题意：给出乘法表
1  2  3  4  5
2  4  6  8  10
3  6  9  12 15
4  8  12 16 20
5  10 15 20 25
从左上角开始选n行m列，问这m*n个数中第k大的数是多少？

思路：
二分法。二分答案，对于枚举的答案，能计算出每行小于等于该数的数字个数，相加记得整个矩阵中小于等于该数的数字个数total，total和k比较即可更新上下界。
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



int main()
{
	//freopen("in.txt","r",stdin);
	
	long long n,m,k;
	cin>>n>>m>>k;
	long long l=1,r=m*n,mid;
	while(l<r){
		mid=(l+r)>>1;
		long long t,total=0;
		for(int i=1;i<=n;i++){
			t=mid/i;
			total+=min(m,t);
		}

		if(total<k) l=mid+1;
		else r=mid;
	}
	cout<<l<<endl;
    return 0;
}