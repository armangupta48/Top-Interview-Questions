/*
Given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)
Example 2:

Input: nums = [3,3,6,8], target = 10
Output: 6
Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
Example 3:

Input: nums = [2,3,3,4,6,7], target = 12
Output: 61
Explanation: There are 63 non-empty subsequences, two of them don't satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).
Example 4:

Input: nums = [5,2,4,1,7,6,8], target = 16
Output: 127
Explanation: All non-empty subset satisfy the condition (2^7 - 1) = 127
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
1 <= target <= 106
*/
class Solution {
public:
    int helper(int x,int y)
    {
        if(y==1) return x;
        if(y==0) return 1;
        long long int ans = 1;
        if(y%2==0)
        {
            ans=helper(x,y/2);
                ans*=ans;
        }
        else
        {
            ans= helper(x,y-1);
                ans*=x;
        }
        return ans%1000000007;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int s = 0;
        int e = nums.size()-1;
        int ans = 0;
        while(s<=e)
        {
            if(nums[s]+nums[e]<=target)
            {
                ans+=helper(2,e-s);
                ans=ans%1000000007;
                s++;
            }
            else
                e--;
        }
        return ans%1000000007;
    }
};
