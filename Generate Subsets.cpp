Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(nums,res,tmp,0);
        return res;
    }
    void helper(vector<int>& nums,vector<vector<int>>& res,vector<int>& tmp,int i)
    {  
       
        res.push_back(tmp);
        for(int j = i;j<nums.size();j++)
        {
            tmp.push_back(nums[j]);
            helper(nums,res,tmp,j+1);
            tmp.pop_back();
        }
    }
};

