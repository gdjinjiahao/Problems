/*
���⣺����һ���ַ����������ܻ���Ϊ���ٸ������Ӵ�
˼·������dp����һ�˼���f[i][j],��i��j���Ӵ��Ƿ���ģ��ڶ��˸���f����dp[i]����ǰi���Ӵ����ٻ�����
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
#include <cstdlib>
#include <ctime>



using namespace std;


bool f[1010][1010];
int dp[1010];

int main()
{
	int n;
	cin >> n;
	while (n--) {
		memset(f, false, sizeof(f));
		string str;
		cin >> str;
		int len = str.length();
		for (int i = 1; i <= len; i++) f[i][i] = true;
		for (int l = 2; l <= len; l++)
			for (int i = 1; i + l - 1 <= len; i++) {
				int j = i + l - 1;
				if (str[i - 1] == str[j - 1] && (i + 1 > j - 1 || f[i + 1][j - 1])) f[i][j] = true;
			}

		dp[0] = 0;
		for (int i = 1; i <= len; i++) {
			dp[i] = dp[i - 1] + 1;
			for (int j = i; j > 0; j--) if (f[j][i])
				dp[i] = min(dp[i], dp[j - 1] + 1);

		}
		cout << dp[len] << endl;
	}
	return 0;
}
