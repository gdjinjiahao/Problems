/*
题意：给定分子分母之和，求分子小于分母，且分子分母互质的最大分数
分析：令分子a从n>>1开始，则分母从n-a开始，知道找到a与n-a互质的即可，对于n为偶数，会有a=n-a，但其一定不互质，所以不用特别处理
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

int gcd(int a, int b)
{
	int t = 1;
	while (t)
	{
		t = a%b;
		a = b;
		b = t;
	}
	return a;
}

int main()
{
	int n;
	cin >> n;
	for (int a = (n >> 1); a >= 1; a--) if (gcd(a, n - a) == 1) {
		cout << a << " " << n - a << endl;
		break;
	}
	return 0;
}