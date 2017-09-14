/*
描述
小Hi想知道，如果他每次都按照一种固定的顺序重排数组，那么最少经过几次重排之后数组会恢复初始的顺序？

具体来讲，给定一个1 - N 的排列 P，小Hi每次重排都是把第 i 个元素放到第 Pi个位置上。例如对于 P = (2, 3, 1)，假设初始数组是(1, 2, 3)，重排一次之后变为(3, 1, 2)，重排两次之后变为(2, 3, 1)，重排三次之后变回(1, 2, 3)。

被排数组中的元素可以认为是两两不同的。

输入
第一行一个整数 N ，代表数组的长度。 (1 ≤ N ≤ 100)

第二行N个整数，代表1 - N 的一个排列 P 。

输出
输出最少重排的次数。

样例输入
3
2 3 1
样例输出
3
注：给定的P即时排序数组又是被排数组
分析：求出各个循环节，答案为所有循环节长度的最小公倍数
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

int e[110];
bool vis[110];

int gcd(int a, int b)
{
	int t = 1;
	while (t) {
		t = a%b;
		a = b;
		b = t;
	}
	return a;
}

int lcm(int a, int b)
{
	int t = gcd(a, b);
	return a / t*b;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> e[i];
	memset(vis, false, sizeof(vis));
	int ans = 1;
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		int t = 1, pos = e[i];
		vis[i] = true;
		while (pos != i) {
			t++;
			vis[pos] = true;
			pos = e[pos];
		}
		ans = lcm(ans, t);
	}
	cout << ans << endl;
	return 0;
}