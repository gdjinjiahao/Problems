/*
����
СHi����ڷ���һ֧��Ʊ�ļ۸����ƣ�����Ҫһ�����������������������������3����Ϣ��ָ���

�۸���Ϣ����ʽ��P timestamp price����ʾ��֧��Ʊ�� timestamp ʱ�̼۸��� price��

ɾ���۸�ָ���ʽ��R timestamp������ʱ�����ƣ�СHi�����Խ��Խ��ļ۸����ݡ�һЩ�Ͼɵ����ݻ��ò���Ҫ�����ָ����ɾ�� timestamp ��ǰ������ timestamp ʱ�̣��ļ۸����ݡ�

�۸��ѯָ���ʽ��Q��СHiϣ�����򷵻���ֻ��Ʊ��ߡ���ͺ�����ļ۸�ע���Ѿ���ɾ���ļ۸�Ӧ�ñ�ͳ�ơ�

����һ����������3����Ϣ��ָ������У����ܷ����СHi�����������أ�

����
��1�а���һ������ N (1 �� N �� 500000)����ʾ��Ϣ��ָ����еĳ��ȡ�

��2 - N+1�У�ÿ�а���һ����Ϣ��ָ�

���뱣֤�۸���Ϣ�ǰ��� timestamp �������еģ����ҳ��ֵ� timestamp �ͼ۸�С��100000000��

���
����������ÿһ���۸��ѯָ������ʱ��ߡ���ͺ�����ļ۸�

��������
10
P 1 77
P 2 73
P 5 70
P 7 74
Q
R 4
Q
P 8 78
R 5
Q
�������
77 70 74
74 70 74
78 74 78

������
�����ĿҪ������ʵ��һ�����ݽṹ���Դ���һ�ֶ�Ԫ����< timestamp, price >��

����֧�����²�����

�ڶ�β����һ������
ɾ��timestampС�ڵ��ڸ���ֵ�����ݣ�������������֪����Щ���ݶ��ڶ���
��ѯprice��ߡ���ͺ�timestamp���(��β)������
����1��2�����ö���ʵ�֣�3�����ö�ʵ�֡���������Ҫ�Ѷ��кͶѽ���������е��Ѷȡ��������ڵ����ǴӶ���ɾ�����ݵ�ʱ�����Ǳ���֪����Щ�����ڶ��е�λ�ã�Ȼ����ܽ���ɾ��������Ȥ��ͬѧ�����Լ�ʵ��һ�������Ĵ������Ķѡ�

�������ǽ���һ������set/map��ƽ��������(Java�е�TreeMap��TreeSet, C#�е�SortedSet��SortedDictionary, Python...)��������

����������map<int, int> price������ÿ��timestamp��price�Ƕ��٣�Ҳ����price[timestamp]������timestampʱ�ļ۸�����map�ڲ����ú����ʵ�ֵģ��������Ǵ�price.beign()��price.end()���α�����timestamp��С��������ݡ�

���������multiset<int> prices������û��ɾ�������ݵļ۸񼯺ϡ�ͬ������set/multiset���ɺ����ʵ�ֵģ����Դ�prices.begin()��prices.end()��С����һ�α����ż۸�(��Щ����û�����õĶ��ؼ��ϣ�����Ҳ���������� set<pair<int, int>> �ķ�ʽ�洢������pair�ĵ�һ�ؼ�����price���ڶ��ؼ�����timestamp��)

����������Pָ��ʱ��ֻ�轫���ݲ���price��prices��

if(c == 'P') {
    cin >> t >> p;
    price[t] = p;
    prices.insert(p);
}
����������ɾ��ʱ��ֻ��Ҫ��ͷ��ʼ��price����timestampС�ڵ��ڸ���ֵ�����ݣ�Ȼ������price��prices��ͬʱɾ����Щ���ݡ���Ȼһ��R��������ɾ�����������ݣ����Ǿ�̯����ÿ�β���ֻ��ɾ��һ�����ݣ����Ӷ���O(logN)�ġ�

if(c == 'R') {
    cin >> t;
    while(price.size() != 0 && price.begin()->first <= t) {
        auto itr = prices.find(price.begin()->second);
        prices.erase(itr);
        price.erase(price.begin());
    }
}
���ڲ�ѯ����߼۸񱣴���prices.begin()����ͼ۸񱣴���prices.rbegin(), ����۸񱣴���price.rbegin()��

if(c == 'Q') {
    cout << *(prices.rbegin()) << ' ' << *(prices.begin()) << ' ' << price.rbegin()->second << endl;
}
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
using namespace std;

pair<int,int> q[500010];
int s,e;
multiset<int> ps;

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);getchar();
	s=0;
	e=-1;

	for(int i=0;i<n;i++){
		char op;
		scanf("%c",&op);getchar();
		if(op=='P'){
			e++;
			scanf("%d%d",&q[e].first,&q[e].second);getchar();
			ps.insert(q[e].second);
		}
		else if(op=='R'){
			int key;
			scanf("%d",&key);getchar();
			while(s<=e&&q[s].first<=key){
				int t=q[s].second;
				multiset<int>::iterator ite=ps.find(t);
				ps.erase(ite);
				s++;
			}
		}
		else
			printf("%d %d %d\n",*ps.rbegin(),*ps.begin(),q[e].second);
	}
    return 0;
}