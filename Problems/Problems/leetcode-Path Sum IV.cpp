#include <vector>
using namespace std;

/*
题意：给一颗树，深度不超过4，每个节点用一个三位数表示，每位含义如下
1.The hundreds digit represents the depth D of this node, 1 <= D <= 4.
2.The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. The position is the same as that in a full binary tree.
3.The units digit represents the value V of this node, 0 <= V <= 9.
求所有路径(根节点到叶节点算一个路径，路径之和为路径上节点值之和)之和。
*/

class Solution {
private:
    int ans;
public:
    void dfs(int* a,int rt,int total){
	if(a[rt]==-1) return ;
	total+=a[rt];
    if(a[rt<<1]==-1&&a[rt<<1|1]==-1) ans+=total;
	dfs(a,rt<<1,total);
	dfs(a,rt<<1|1,total);
}

int pathSum(vector<int>& nums) {
        int a[40];
		for(int i=0;i<40;i++) a[i]=-1;
		for(int i=0;i<nums.size();i++){
			int d1=nums[i]/100,d2=(nums[i]/10)%10,d3=nums[i]%10;
			int pos=(1<<(d1-1))+d2-1;
			a[pos]=d3;
		}
		ans=0;
		dfs(a,1,0);
		return ans;
	}
};