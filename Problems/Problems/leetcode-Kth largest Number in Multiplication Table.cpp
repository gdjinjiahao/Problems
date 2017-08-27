/*
�����codeforce 448��ͬ������codeforce�Ĵ��롣
���⣺�����˷���
1  2  3  4  5
2  4  6  8  10
3  6  9  12 15
4  8  12 16 20
5  10 15 20 25
�����Ͻǿ�ʼѡn��m�У�����m*n�����е�k������Ƕ��٣�

˼·��
���ַ������ִ𰸣�����ö�ٵĴ𰸣��ܼ����ÿ��С�ڵ��ڸ��������ָ�������Ӽǵ�����������С�ڵ��ڸ��������ָ���total��total��k�Ƚϼ��ɸ������½硣
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