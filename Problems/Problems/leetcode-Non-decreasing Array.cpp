#include <vector>
using namespace std;

/*
���⣺����һ�����飬������ı�һ�����֣��ܷ������б�Ϊ�ǵݼ�����
����������nums[i-1]>nums[i]�����ԣ��ֱ����޸�i-1��i�������֣��޸ĺ�����Ƿ�ǵݼ���
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
			//��i-1���޸���Ҫ�ж�һ���Ƿ�Խ��
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