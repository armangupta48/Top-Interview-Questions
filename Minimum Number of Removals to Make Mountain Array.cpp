/*
Hard

255

4

Add to List

Share
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.

 

Example 1:

Input: nums = [1,3,1]
Output: 0
Explanation: The array itself is a mountain array so we do not need to remove any elements.
Example 2:

Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
Example 3:

Input: nums = [4,3,2,1,1,2,3,1]
Output: 4
Example 4:

Input: nums = [1,2,3,4,4,3,2,1]
Output: 1
 

Constraints:

3 <= nums.length <= 1000
1 <= nums[i] <= 109


It is guaranteed that you can make a mountain array out of nums.
*/

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        for(int i = 1;i<nums.size();i++)
        {
            int ans = 0;
            for(int j = 0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    ans = max(ans,dp[j]);
                }
            }
            dp[i] = ans+1;
        }
        vector<int> dp1(nums.size(),1);
        for(int i = nums.size()-2;i>=0;i--)
        {
            int ans = 0;
            for(int j = nums.size()-1;j>i;j--)
            {
                if(nums[i]>nums[j])
                {
                    ans = max(ans,dp1[j]);
                }
            }
            dp1[i] = ans+1;
        }
        int res = 0;
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(dp[i]>1 && dp1[i]>1)
            res=max(res,(dp[i]+dp1[i])-1);
        }
        return nums.size()-res;
    }
};

