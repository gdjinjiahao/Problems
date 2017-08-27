#include <vector>
using namespace std;

/*
题意：给定一个数组，问至多改变一个数字，能否是序列变为非递减序列
分析：查找nums[i-1]>nums[i]的数对，分别检查修改i-1和i两个数字，修改后检验是否非递减。
*/

class Solution {
public:
    
    bool isnd(vector<int>& nums)
	{
		for(int i=1;i<nums.size();i++) if(nums[i-1]>nums[i])
			return false;
		return true;
	}
    
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()<=2) return true;
		if(isnd(nums)) return true;
		bool yes=false;
		for(int i=1;i<=nums.size();i++) if(nums[i-1]>nums[i]){
			int t;
			t=nums[i-1];
			//对i-1的修改需要判断一下是否越界
			if(i-2>=0){
				nums[i-1]=nums[i-2];
				yes=yes||isnd(nums);
			}
			else{
				nums[i-1]=nums[i]-1;
				yes=yes||isnd(nums);
			}
			nums[i-1]=t;

			nums[i]=nums[i-1];
			yes=yes||isnd(nums);
			break;
		}
		return yes;
	 }
};