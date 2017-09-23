/*
题意：给定2n个人的体重，从中去掉2人，剩余的两两一组，求所有组的组员体重差值的绝对值的最小和
分析：有n的规模最大为50，故暴力枚举去掉的两个人即可
*/
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
const double esp = 0.00000001;

//ostringstream s1, s2;

vector<int> w;

int  _abs(int x)
{
	if (x < 0) return -x;
	return x;
}

int main()
{
	int n;
	cin >> n;
	n <<= 1;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		w.push_back(t);
	}
	sort(w.begin(), w.end());
	int ans = 1000000;
	for (int i = 0; i<n; i++)
		for (int j = 0; j < i; j++) {
			int p = 0, tw = 0, cnt = 2;
			while (cnt < n) {
				int a, b;
				while (p == i || p == j) p++;
				a = w[p++];
				while (p == i || p == j) p++;
				b = w[p++];
				tw += _abs(a - b);
				cnt += 2;
			}
			ans = min(ans, tw);
		}
	cout << ans << endl;
	return 0;
}