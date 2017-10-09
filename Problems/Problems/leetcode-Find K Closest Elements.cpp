/*
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104
分析：利用二分找到最接近x的数字，然后向两端线性扩展
*/
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		ans.clear();
		int l = 0, r = arr.size() - 1;
		while (l<r) {
			int mid = (l + r) >> 1;
			if (arr[mid] >= x) r = mid;
			else l = mid + 1;
		}
		if (l>0) {
			if (_abs(arr[l - 1] - x) <= _abs(arr[l] - x)) l--;
		}
		int cnt = 1;
		ans.push_back(arr[l]);
		r = l + 1; l = l - 1;
		while (cnt<k) {
			if (l >= 0 && r<arr.size()) {
				if (_abs(arr[l] - x)>_abs(arr[r] - x)) {
					ans.push_back(arr[r]);
					r++;
				}
				else {
					ans.push_back(arr[l]);
					l--;
				}
			}
			else if (l >= 0) {
				ans.push_back(arr[l]);
				l--;
			}
			else {
				ans.push_back(arr[r]);
				r++;
			}
			cnt++;
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
private:
	vector<int> ans;
	int _abs(int x)
	{
		if (x<0) return -x;
		return x;
	}
};