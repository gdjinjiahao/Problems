/*
描述
给定一个十进制小数X，判断X的二进制表示是否是有限确定的。

例如0.5的二进制表示是0.1，0.75的二进制表示是0.11，0.3没有确定有限的二进制表示。

输入
第一行包含一个整数 T (1 ≤ T ≤ 10)，表示测试数据的组数。

以下T行每行包含一个十进制小数 X (0 < X < 1)。 X一定是以"0."开头，小数部分不超过100位。

输出
对于每组输入，输出 X 的二进制表示或者NO(如果 X 没有确定有限的二进制表示）。

样例输入
3
0.5
0.75
0.3
样例输出
0.1
0.11
NO

分析：
二进制小数转换十进制——乘2取整
每轮若最低位不是0或5，则没有有限的表示。
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

int num[110];
char t[110];
vector<int> ans;
int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);getchar();
	while(n--){
		scanf("%s",t);getchar();
		int len=strlen(t)-1;
		for(int i=2;i<=len;i++) num[i-1]=t[i]-'0';

		len--;

		ans.clear();
		while(len){
			if(num[len]!=0&&num[len]!=5){
				ans.clear();
				break;
			}

			int temp=0;
			for(int i=len;i>=0;i--){
				num[i]=(num[i]<<1)+temp;
				temp=num[i]/10;
				num[i]%=10;
			}
			ans.push_back(num[0]);
			num[0]=0;
			while(len>=1&&num[len]==0) len--;
		}
		if(!ans.size()) printf("NO\n");
		else{
			printf("0.");
			for(int i=0;i<ans.size();i++) printf("%d",ans[i]);
			printf("\n");
		}
	}
    return 0;
}