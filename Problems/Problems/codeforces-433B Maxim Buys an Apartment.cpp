/*
题意：给定n个房间，其中k个房间有人住，一间好房间意味着没人住且相邻的房间有人住，计算好房间数量的最小值和最大值
分析：分情况讨论即可，首先看k，若k=0或k=n，则好房间为0，否则最少有一间好房间（1-k号房间均住人，则唯一好房间k+1）。每三个连续的房间一组，每组中间房间住人，
则判断组数和k的关系即可
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


int main()
{
	int n, k;
	scanf_s("%d%d", &n, &k);
	if (!k) {
		printf("0 0\n");
		return 0;
	}
	if (k < n)
		printf("1 ");
	else
		printf("0 ");
	int t = n / 3;
	if (t >= k) printf("%d\n", k << 1);
	else {
		printf("%d", n - k);
	}
	return 0;
}