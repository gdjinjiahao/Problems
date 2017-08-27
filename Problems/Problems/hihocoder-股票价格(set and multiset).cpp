/*
描述
小Hi最近在分析一支股票的价格走势，他需要一个程序来辅助分析。这个程序会接收3种消息（指令）：

价格信息，格式是P timestamp price：表示这支股票在 timestamp 时刻价格是 price。

删除价格指令，格式是R timestamp：随着时间推移，小Hi会积累越来越多的价格数据。一些老旧的数据会变得不重要。这个指定会删除 timestamp 以前（包括 timestamp 时刻）的价格数据。

价格查询指令，格式是Q：小Hi希望程序返回这只股票最高、最低和最近的价格。注意已经被删除的价格不应该被统计。

给定一个包含以上3种信息（指令）的序列，你能否帮助小Hi完成这个程序呢？

输入
第1行包含一个整数 N (1 ≤ N ≤ 500000)，表示消息（指令）序列的长度。

第2 - N+1行，每行包含一条消息或指令。

输入保证价格信息是按照 timestamp 升序排列的，并且出现的 timestamp 和价格小于100000000。

输出
对于输入中每一条价格查询指令，输出当时最高、最低和最近的价格。

样例输入
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
样例输出
77 70 74
74 70 74
78 74 78

分析：
这道题目要求我们实现一个数据结构可以处理一种二元数据< timestamp, price >。

并其支持以下操作：

在队尾插入一条数据
删除timestamp小于等于给定值的数据，根据题意我们知道这些数据都在队首
查询price最高、最低和timestamp最大(队尾)的数据
其中1和2可以用队列实现，3可以用堆实现。但是我们要把队列和堆结合起来就有点难度。困难在于当我们从队首删除数据的时候，我们必须知道这些数据在堆中的位置，然后才能进行删除。有兴趣的同学可以自己实现一个完整的带索引的堆。

这里我们介绍一种利用set/map的平衡树特性(Java中的TreeMap和TreeSet, C#中的SortedSet和SortedDictionary, Python...)的做法。

首先我们用map<int, int> price来保存每个timestamp的price是多少，也就是price[timestamp]保存着timestamp时的价格。由于map内部是用红黑树实现的，所以我们从price.beign()到price.end()依次保存着timestamp从小到大的数据。

其次我们用multiset<int> prices来保存没被删掉的数据的价格集合。同样由于set/multiset是由红黑树实现的，所以从prices.begin()到prices.end()从小到大一次保存着价格。(有些语言没有内置的多重集合，我们也可以用类似 set<pair<int, int>> 的方式存储，其中pair的第一关键字是price，第二关键字是timestamp。)

当我们遇到P指令时，只需将数据插入price和prices：

if(c == 'P') {
    cin >> t >> p;
    price[t] = p;
    prices.insert(p);
}
当我们遇到删除时，只需要从头开始在price里找timestamp小于等于给定值的数据，然后再在price和prices里同时删除这些数据。虽然一次R操作可能删除掉多条数据，但是均摊下来每次操作只会删除一条数据，复杂度是O(logN)的。

if(c == 'R') {
    cin >> t;
    while(price.size() != 0 && price.begin()->first <= t) {
        auto itr = prices.find(price.begin()->second);
        prices.erase(itr);
        price.erase(price.begin());
    }
}
对于查询，最高价格保存在prices.begin()，最低价格保存在prices.rbegin(), 最近价格保存在price.rbegin()。

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