/*
���⣺����n�����䣬����k����������ס��һ��÷�����ζ��û��ס�����ڵķ�������ס������÷�����������Сֵ�����ֵ
��������������ۼ��ɣ����ȿ�k����k=0��k=n����÷���Ϊ0������������һ��÷��䣨1-k�ŷ����ס�ˣ���Ψһ�÷���k+1����ÿ���������ķ���һ�飬ÿ���м䷿��ס�ˣ�
���ж�������k�Ĺ�ϵ����
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