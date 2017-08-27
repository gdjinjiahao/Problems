#include <vector>
using namespace std;

/*
���⣺��һ��������Ȳ�����4��ÿ���ڵ���һ����λ����ʾ��ÿλ��������
1.The hundreds digit represents the depth D of this node, 1 <= D <= 4.
2.The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. The position is the same as that in a full binary tree.
3.The units digit represents the value V of this node, 0 <= V <= 9.
������·��(���ڵ㵽Ҷ�ڵ���һ��·����·��֮��Ϊ·���Ͻڵ�ֵ֮��)֮�͡�
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