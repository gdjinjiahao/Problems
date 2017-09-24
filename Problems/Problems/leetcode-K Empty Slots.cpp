/*
There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.

Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.

For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 1 to N.

Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is k and these flowers are not blooming.

If there isn't such day, output -1.

Example 1:
Input:
flowers: [1,3,2]
k: 1
Output: 2
Explanation: In the second day, the first and the third flower have become blooming.
Example 2:
Input:
flowers: [1,2,3]
k: 1
Output: -1
Note:
The given array will be in the range [1, 20000].
���⣺n�໨��n�쿪�ţ�ÿ�쿪һ�䣬ÿ�仨λ��һ�������У�����1-n��ţ����ź�һֱ���ţ��������Ŀ���˳���һ������k�����Ƿ����һ�죬���컨�����Ƿ�������俪�ŵĻ����м���k�䲻���ŵĻ���
���������α���ÿһ�죬����Ļ���i���ź�ö��i-k-1��i+k+1�������Խ��Ļ��������仨���������仨�п��ŵģ����ж�����Ƿ���δ���ŵĻ��䣬
�жϲ��������߶���ʵ�������ѯ��
*/
#include <cstring>
class Solution {
public:
	int kEmptySlots(vector<int>& flowers, int k) {
		int n = flowers.size();
		memset(tree, false, sizeof(tree));
		memset(fb, false, sizeof(fb));
		for (int i = 0; i<n; i++) {
			int f = flowers[i];
			fb[f] = true;
			update(f, 1, 1, n);
			if (f - k - 1 >= 1 && fb[f - k - 1]) {
				if (!query(1, 1, n, f - k, f - 1)) return i + 1;
			}
			if (f + k + 1 <= n&&fb[f + k + 1]) {
				if (!query(1, 1, n, f + 1, f + k)) return i + 1;
			}
		}
		return -1;
	}
private:
	bool fb[20010];
	bool tree[20010 << 2];
	bool query(int rt, int l, int r, int L, int R)
	{
		if (l >= L&&r <= R)
			return tree[rt];
		int m = (l + r) >> 1;
		bool ans = false;
		if (L <= m) ans = ans || query(rt << 1, l, m, L, R);
		if (R>m) ans = ans || query(rt << 1 | 1, m + 1, r, L, R);
		return ans;
	}
	void update(int p, int rt, int l, int r)
	{
		tree[rt] = true;
		if (l == r)
			return;
		int mid = (l + r) >> 1;
		if (p <= mid) update(p, rt << 1, l, mid);
		else update(p, rt << 1 | 1, mid + 1, r);
	}
};