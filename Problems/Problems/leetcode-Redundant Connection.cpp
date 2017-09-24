/*
We are given a "tree" in the form of a 2D-array, with distinct values for each node.

In the given 2D-array, each element pair [u, v] represents that v is a child of u in the tree.

We can remove exactly one redundant pair in this "tree" to make the result a tree.

You need to find and output such a pair. If there are multiple answers for this question, output the one appearing last in the 2D-array. There is always at least one answer.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: Original tree will be like this:
1
/ \
2 - 3
Example 2:
Input: [[1,2], [1,3], [3,1]]
Output: [3,1]
Explanation: Original tree will be like this:
1
/ \\
2   3
Note:
The size of the input 2D-array will be between 1 and 1000.
Every integer represented in the 2D-array will be between 1 and 2000.
分析：利用并查集判断，若某条边的两个定点属于同一集合，则该边可以消除
*/
class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		for (int i = 1; i <= 2000; i++) f[i] = i;
		vector<int> ans;
		for (int i = 0; i<edges.size(); i++) {
			int u = edges[i][0], v = edges[i][1];
			int fu = getf(u), fv = getf(v);
			if (fu == fv) {
				ans.push_back(u);
				ans.push_back(v);
				break;
			}
			f[fu] = fv;
		}
		return ans;
	}
private:
	int f[2010];
	int getf(int x)
	{
		if (f[x] == x) return x;
		return f[x] = getf(f[x]);
	}
};