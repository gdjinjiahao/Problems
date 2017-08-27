/*
����
СHiϣ��ѹ��һ��ֻ������д��ĸ'A'-'Z'���ַ�������ʹ�õķ����ǣ����ĳ���Ӵ� S ���������� X �Σ�����'X(S)'����ʾ������AAAAAAAAAABABABCCD������10(A)2(BA)B2(C)D��ʾ��

���⣬����ѹ�������ǿ���Ƕ�׵ģ�����HIHOHIHOCODERHIHOHIHOCODER���Ա�ʾ��2(2(HIHO)CODER)��

����һ���ַ��� S ���Ϸ���ѹ����ʾ�����кܶ��֡�����AAAAAAAAAABABABCCD�����Ա�ʾ��9(A)3(AB)CCD��СHiϣ��֪��������̵ı�ʾ���������Ƕ��١�

����
��һ��һ�������� T (1 �� T �� 10)����ʾ�������ݵ�������

���� T ��ÿ��һ���ַ��� S �����Ȳ�����100��

���
����ÿ�����ݣ������̵ı�ʾ�����ĳ��ȡ�

��������
3
ABC
AAAAAAAAAABABABCCD
HIHOHIHOCODERHIHOHIHOCODER
�������
3
12
15
��������̬�滮����Ҫ�ǲ�������
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

bool zip(int l,int r,int k)//k����
{
	//�ж��Ƿ����ѹ��
	int n=(r-l+1)/k;
	//ÿ���Ӵ��͵�һ���Ӵ��Ƚϣ����Ƚ�n-1��
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
		for(int l=2;l<=len;l++){//ö�ٳ���
			for(int i=0;i+l-1<len;i++){
				//����[i,last]�������Ӵ�
				int last=i+l-1;
				//��һ�������ԭ��
				f[i][last]=l;
				//�ڶ��������ƴ��
				for(int k=i;k<last;k++){
					f[i][last]=min(f[i][last],f[i][k]+f[k+1][last]);
				}
				//�����������ѹ��
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