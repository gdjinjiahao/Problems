#include <vector>
using namespace std;

/*
题意：Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n and obeys the following requirement: 
Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.

If there are multiple answers, print any of them.

分析：先构造差值为k的，再构造差值为k-1的等等，纸上模拟一下即可知道思路，即1和k+1组合，k+1和2组合，2和k组合，依次类推，k+1之后的数字正常输出即可。

1，2，3，……，k-1，k，k+1

构造结果为：
1，k+1，2，k，3，k-1……，k+2，k+3，……，n
*/

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int l=1,r=k+1;
        while(l<=r){
            if(l!=r){
                ans.push_back(l);
                ans.push_back(r);
            }
            else
                ans.push_back(l);
            l++;r--;
        }
        for(int i=k+2;i<=n;i++) ans.push_back(i);
        return ans;
    }
};