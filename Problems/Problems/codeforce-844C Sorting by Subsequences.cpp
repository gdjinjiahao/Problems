/*
���⣺����n����ͬ���֣������ֳܷɶ�������У�ʹ��ÿ������������������У����ñ�֤������������������������λ�ò��䣩��������������
��������Էֳɼ������У������ÿ�����еĳ��Ⱥ�Ԫ�ض�Ӧ�������š�
������
��ԭ����Ϊa��aԪ������������Ϊb
a������ô���֣����������궼��b����a��ÿ��Ԫ�ص�����λ����ȷ����
����ÿ�黮�֣����ҵ�a��һ����û�б������Ԫ��a[i]���ҵ���b�е�λ��j����λ��������Ҫ��a[i]����jλ�÷��õĲ���a[i]��a[j]������Ҫ���ҵ�a[j]��b
�е�λ�ã�������Ȼ���γ�һ����·�������·���ǻ��ֺõ�һ�顣
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

int e[100010],e1[100010];
bool vis[100010];
map<int,int> m;
vector<int> p[100010];

int main()
{
	//freopen("in.txt","r",stdin);
	//vis[i]��ʾ��i��������û�б�����
	memset(vis,false,sizeof(vis));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",e+i);
		e1[i]=e[i];
		p[i].clear();
	}
	sort(e1+1,e1+n+1);
	for(int i=1;i<=n;i++) m[e1[i]]=i;
	int k=0;
	for(int i=1;i<=n;i++) if(!vis[i]){
		int t=i;
		//Ѱ�һ�·
		do{
			vis[t]=true;
			p[k].push_back(t);
			t=m[e[t]];
		}while(t!=i);
		k++;
	}
	printf("%d\n",k);
	for(int i=0;i<k;i++){
		printf("%d",p[i].size());
		sort(p[i].begin(),p[i].end());
		for(int j=0;j<p[i].size();j++){
			printf(" %d",p[i][j]);
		}
		printf("\n");
	}
    return 0;
}