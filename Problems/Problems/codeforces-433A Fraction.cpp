/*
���⣺�������ӷ�ĸ֮�ͣ������С�ڷ�ĸ���ҷ��ӷ�ĸ���ʵ�������
�����������a��n>>1��ʼ�����ĸ��n-a��ʼ��֪���ҵ�a��n-a���ʵļ��ɣ�����nΪż��������a=n-a������һ�������ʣ����Բ����ر���
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