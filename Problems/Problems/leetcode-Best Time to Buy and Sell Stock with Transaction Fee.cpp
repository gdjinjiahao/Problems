/*
给定一个数组prices，prices[i]表示一只股票第i天的价格，还给定一个整数fee，表示交易费用
可以在任意一天买或卖这支股票，一天只能进行一种操作，且买必须在卖之后，求最大收益。

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.

分析：动态规划求解，定义f[i]为从第1天开始到第i天（包括第i天）的最大收益
显然第i天要么无操作，要么把之前买的一只股票卖了，对于第二种操作需要枚举最近一次买股票的日期
f[i]=MAX{f[i-1],MAX{prices[i]-prices[j]-fee+f[j-1]}},1<=j<i
这样复杂度是O(n^2),太大，观察j的部分，发现对于任意i，都是寻找t = -prices[j]-fee+f[j-1]+f[j-1]的最大值
故每次计算完f[i]后更新t即可
这样复杂度降为O(n)
*/
class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		long long f[50010];
		f[0] = f[1] = 0;
		long long t = f[0] - prices[0] - fee;
		for (int i = 1; i<prices.size(); i++) {
			f[i + 1] = _max(f[i], prices[i] + t);
			t = _max(t, f[i + 1] - prices[i] - fee);


		}
		long long ans = f[prices.size()];
		if (ans <= 0) return 0;
		return ans;
	}
private:
	long long _max(long long a, long long b)
	{
		if (a>b) return a;
		return b;
	}
};