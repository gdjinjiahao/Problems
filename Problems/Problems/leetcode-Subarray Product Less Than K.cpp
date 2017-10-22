/*
Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Note:

0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.

分析：显然,若某一子数组nums[l……r]满足条件，则该子数组中任一子数组也满足条件
首先计算长度为i的数组有多少子数组
f[i]=f[i-1]+i
之后以第一个元素为起点构造第一个满足条件的最长子数组，构造完成后，显然其中任一子数组均满足条件，记录此区间各元素乘积
之后每次i向后遍历一个元素，调整j似的nums[j……i]满足条件，此时只需计数包含i元素的子数组即可（不包含i元素的字数字在之前必然已经计算过了），即i-j+1
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