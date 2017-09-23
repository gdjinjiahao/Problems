/*
题意：给定一个数字，判断添加（可添加0个）前导0后能否构成回文数字
分析：找到最低位非0数字即可
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


int main()
{
	string t;
	cin >> t;
	int l = 0, r = t.length() - 1;
	while (r > l&&t[r] == '0') r--;
	bool flag = true;
	while (l < r) {
		if (t[l] != t[r]) {
			flag = false;
			break;
		}
		l++; r--;
	}
	cout << (flag ? "YES" : "NO") << endl;
	return 0;
}