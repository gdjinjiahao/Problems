/*
����һ������prices��prices[i]��ʾһֻ��Ʊ��i��ļ۸񣬻�����һ������fee����ʾ���׷���
����������һ���������֧��Ʊ��һ��ֻ�ܽ���һ�ֲ����������������֮����������档

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

��������̬�滮��⣬����f[i]Ϊ�ӵ�1�쿪ʼ����i�죨������i�죩���������
��Ȼ��i��Ҫô�޲�����Ҫô��֮ǰ���һֻ��Ʊ���ˣ����ڵڶ��ֲ�����Ҫö�����һ�����Ʊ������
f[i]=MAX{f[i-1],MAX{prices[i]-prices[j]-fee+f[j-1]}},1<=j<i
�������Ӷ���O(n^2),̫�󣬹۲�j�Ĳ��֣����ֶ�������i������Ѱ��t = -prices[j]-fee+f[j-1]+f[j-1]�����ֵ
��ÿ�μ�����f[i]�����t����
�������ӶȽ�ΪO(n)
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