/*
���⣺����2n���˵����أ�����ȥ��2�ˣ�ʣ�������һ�飬�����������Ա���ز�ֵ�ľ���ֵ����С��
��������n�Ĺ�ģ���Ϊ50���ʱ���ö��ȥ���������˼���
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