/*
����
����һ��ʮ����С��X���ж�X�Ķ����Ʊ�ʾ�Ƿ�������ȷ���ġ�

����0.5�Ķ����Ʊ�ʾ��0.1��0.75�Ķ����Ʊ�ʾ��0.11��0.3û��ȷ�����޵Ķ����Ʊ�ʾ��

����
��һ�а���һ������ T (1 �� T �� 10)����ʾ�������ݵ�������

����T��ÿ�а���һ��ʮ����С�� X (0 < X < 1)�� Xһ������"0."��ͷ��С�����ֲ�����100λ��

���
����ÿ�����룬��� X �Ķ����Ʊ�ʾ����NO(��� X û��ȷ�����޵Ķ����Ʊ�ʾ����

��������
3
0.5
0.75
0.3
�������
0.1
0.11
NO

������
������С��ת��ʮ���ơ�����2ȡ��
ÿ�������λ����0��5����û�����޵ı�ʾ��
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