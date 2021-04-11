/*
Given an integer array nums, return all the different possible increasing subsequences of the given array with at least two elements. You may return the answer in any order.

The given array may contain duplicates, and two equal integers should also be considered a special case of increasing sequence.

 

Example 1:

Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
Example 2:

Input: nums = [4,4,3,2,1]
Output: [[4,4]]
 

Constraints:

1 <= nums.length <= 15
-100 <= nums[i] <= 100
*/
class Solution {
public:
    vector<vector<int>> res;
    map<vector<int>,int> m;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        helper(nums,temp,0);
        return res;
    }
    void helper(vector<int>& nums,vector<int>& tmp,int start)
    {
        if(tmp.size() >=2){
            if(!m.count(tmp))
                res.push_back(tmp);
            m[tmp] = 1;
        }
        if(start >=nums.size()) return;
        for(int i = start;i<nums.size();i++)
        {
        if(tmp.size()==0 || tmp[tmp.size()-1]<=nums[i])
        {
            tmp.push_back(nums[i]);
            helper(nums,tmp,i+1);
            tmp.pop_back();
        }
        }
    }
};

