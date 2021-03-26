46. Permutations
Medium

5672

130

Add to List

Share
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.


---------------------------------------------
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        for(int i = 0;i<nums.size();i++)
        {
            helper(res,nums,tmp,i);
        }
        return res;
    }
   void helper(vector<vector<int>>& res,vector<int>& nums,vector<int>& tmp,int c)
   {
       if(tmp.size()==nums.size())
       {
           res.push_back(tmp);
           return;
       }
       for(int i = 0;i<nums.size();i++)
       {
           if(i==c)
               continue;
           else
           {
               tmp.push_back(nums[i]);
               helper(nums)
           }
       }
       
   }
};
