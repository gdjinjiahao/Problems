/*
���⣺����һ�����֣��ж���ӣ������0����ǰ��0���ܷ񹹳ɻ�������
�������ҵ����λ��0���ּ���
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