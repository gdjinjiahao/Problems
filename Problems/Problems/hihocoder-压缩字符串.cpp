/*
描述
小Hi希望压缩一个只包含大写字母'A'-'Z'的字符串。他使用的方法是：如果某个子串 S 连续出现了 X 次，就用'X(S)'来表示。例如AAAAAAAAAABABABCCD可以用10(A)2(BA)B2(C)D表示。

此外，这种压缩方法是可以嵌套的，例如HIHOHIHOCODERHIHOHIHOCODER可以表示成2(2(HIHO)CODER)。

对于一个字符串 S ，合法的压缩表示可能有很多种。例如AAAAAAAAAABABABCCD还可以表示成9(A)3(AB)CCD。小Hi希望知道其中最短的表示方法长度是多少。

输入
第一行一个正整数 T (1 ≤ T ≤ 10)，表示测试数据的组数。

以下 T 行每行一个字符串 S ，长度不超过100。

输出
对于每组数据，输出最短的表示方法的长度。

样例输入
3
ABC
AAAAAAAAAABABABCCD
HIHOHIHOCODERHIHOHIHOCODER
样例输出
3
12
15
分析：动态规划，主要是操作分类
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
int f[110][110];
char str[110];

bool zip(int l,int r,int k)//k表长度
{
	//判断是否可以压缩
	int n=(r-l+1)/k;
	//每个子串和第一个子串比较，共比较n-1次
	for(int temp=1;temp<n;temp++){
		for(int i=l+k;i<=r;i+=k){
			for(int j=0;j<k;j++) if(str[l+j]!=str[i+j])
				return false;
		}
	}

	return true;
}

int main()
{
	int T;
	cin>>T;getchar();
	while(T--){
		cin.getline(str,110);
		memset(f,0,sizeof(f));
		int len=strlen(str);
		for(int i=0;i<len;i++) f[i][i]=1;
		for(int l=2;l<=len;l++){//枚举长度
			for(int i=0;i+l-1<len;i++){
				//计算[i,last]闭区间子串
				int last=i+l-1;
				//第一种情况，原串
				f[i][last]=l;
				//第二种情况，拼接
				for(int k=i;k<last;k++){
					f[i][last]=min(f[i][last],f[i][k]+f[k+1][last]);
				}
				//第三种情况，压缩
				for(int k=1;k<l;k++) if(l%k==0){
					if(zip(i,last,k)){
						int ans=2+f[i][i+k-1];
						int t=l/k;
						while(t) {ans++;t/=10;}
						f[i][last]=min(f[i][last],ans);
					}
				}
			}
		}
		cout<<f[0][len-1]<<endl;
	}
}