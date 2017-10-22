/*
题意：给定两个字符串s1,s2,从两者中删除一些字符后，可使两串相等，删除一个字符的代价为该字符对应的ASCII码值，计算最小代价

0 < s1.length, s2.length <= 1000.

分析；动态规划，定义f[i][j]为使s1中前i个字符与s2中前j个字符想等的最小代价
若s1[i]==s2[j] f[i][j]=f[i-1][j-1]
若s1[i]!=s2[j] f[i][j]=MAX{f[i-1][j]+s1[i], f[i][j-1]+s2[j], f[i-1][j-1]+s1[i]+s2[j]}

f[0][0]=0
f[i][0]=f[i-1][0]+s1[i]
f[0][j]=f[0][j-1]+s2[j]
*/
class Solution {
public:
	int minimumDeleteSum(string s1, string s2) {
		int f[1010][1010];

		int l1 = s1.length(), l2 = s2.length();

		f[0][0] = 0;
		for (int i = 1; i <= l1; i++) f[i][0] = f[i - 1][0] + (int)s1[i - 1];
		for (int j = 1; j <= l2; j++) f[0][j] = f[0][j - 1] + (int)s2[j - 1];


		for (int i = 1; i <= l1; i++)
			for (int j = 1; j <= l2; j++) {
				char c1 = s1[i - 1], c2 = s2[j - 1];
				if (c1 == c2) f[i][j] = f[i - 1][j - 1];
				else {
					f[i][j] = _fmin(f[i][j - 1] + (int)c2, f[i - 1][j] + (int)c1);
					f[i][j] = _fmin(f[i][j], f[i - 1][j - 1] + (int)(c1 + c2));
				}

			}

		return f[l1][l2];
	}
private:
	long long _fmin(long long a, long long b)
	{
		if (a >= b) return b;
		return a;
	}
};