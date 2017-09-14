/*
题意：有n个航班，第i个航班原本计划在i时刻起飞，现因技术问题，前k(1<=k<=n<=300000)个时刻不能有航班起飞，给出每个飞机每晚一个单位时刻需要
付出的代价，并要求i航班不能早于i时刻起飞，计算所有飞机最小代价，并给出每个飞机的起飞时刻

Input
The first line contains two integers n and k (1 ≤ k ≤ n ≤ 300 000), here n is the number of flights, and k is the number of minutes in the beginning of the day that the flights did not depart.

The second line contains n integers c1, c2, ..., cn (1 ≤ ci ≤ 107), here ci is the cost of delaying the i-th flight for one minute.

Output
The first line must contain the minimum possible total cost of delaying the flights.

The second line must contain n different integers t1, t2, ..., tn (k + 1 ≤ ti ≤ k + n), here ti is the minute when the i-th flight must depart. If there are several optimal schedules, print any of them.

Example
input
5 2
4 2 1 10 2
output
20
3 6 7 4 5
分析：优先队列即可，但因为要考虑每个航班有一个最早起飞时刻，所以特别处理一下
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
const double esp = 0.00000001;

struct Node {
	int c, id;
	bool operator < (const struct Node& a)const {
		return c < a.c;
	}
};
priority_queue<struct Node> q;
int ans[300010];

int main()
{
	int n, k;
	struct Node tt;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++) {
		int t;
		scanf("%d", &t);
		tt.c = t;
		tt.id = i;
		q.push(tt);
	}
	long long total = 0;
	for (int i = k + 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		tt.c = t;
		tt.id = i;
		q.push(tt);
		long long ti = q.top().id, tc = q.top().c;
		ans[ti] = i;
		total += tc*(i - ti);
		q.pop();
	}
	for (int i = n + 1; i <= k + n; i++) {
		long long ti = q.top().id, tc = q.top().c;
		ans[ti] = i;
		total += tc*(i - ti);
		q.pop();
	}
	printf("%I64d\n", total);
	for (int i = 1; i <= n; i++) {
		printf("%d", ans[i]);
		if (i != n) printf(" ");
		else printf("\n");
	}
	return 0;
}