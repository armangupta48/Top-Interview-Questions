/*
Given the array nums consisting of n positive integers. You computed the sum of all non-empty continous subarrays from the array and then sort them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 10^9 + 7.

 

Example 1:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13 
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 
Example 2:

Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
Output: 6
Explanation: The given array is the same as example 1. We have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.
Example 3:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
Output: 50
*/

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> dp;
        for(int i = 0;i<n;i++)
        {
            int total = nums[i];
            dp.push_back(total);
            for(int j= i+1;j<n;j++)
            {
                total+=nums[j];
                dp.push_back(total);
            }
        }
        sort(dp.begin(),dp.end());
        for(int i = 1;i<dp.size();i++)
        {
            dp[i] = (dp[i]+dp[i-1])%1000000007;
        }
        left = left-1;
        right = right-1;
        if(left==0)
        {
            return dp[right] % 1000000007;
        }
        return (dp[right] % 1000000007) - (dp[left-1]%1000000007);
    }
};
