/*
����
СHi��֪���������ÿ�ζ�����һ�̶ֹ���˳���������飬��ô���پ�����������֮�������ָ���ʼ��˳��

��������������һ��1 - N ������ P��СHiÿ�����Ŷ��ǰѵ� i ��Ԫ�طŵ��� Pi��λ���ϡ�������� P = (2, 3, 1)�������ʼ������(1, 2, 3)������һ��֮���Ϊ(3, 1, 2)����������֮���Ϊ(2, 3, 1)����������֮����(1, 2, 3)��

���������е�Ԫ�ؿ�����Ϊ��������ͬ�ġ�

����
��һ��һ������ N ����������ĳ��ȡ� (1 �� N �� 100)

�ڶ���N������������1 - N ��һ������ P ��

���
����������ŵĴ�����

��������
3
2 3 1
�������
3
ע��������P��ʱ�����������Ǳ�������
�������������ѭ���ڣ���Ϊ����ѭ���ڳ��ȵ���С������
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