/*
����
����һ���ַ��� S ��������Ҫ������ɾ�Ĳ������԰� S ���һ�������ַ�����

һ�β�������������λ�ò���һ���ַ�������ɾ������һ���ַ������߰�����һ���ַ��޸ĳ����������ַ���

����
�ַ��� S��S �ĳ��Ȳ�����100, ֻ����'A'-'Z'��

���
���ٵ��޸Ĵ�����

��������
ABAD
�������
1
������
��̬�滮����
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