/*
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

 

Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 

Constraints:

2 <= n <= 58
*/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3;i<=n;i++)
        {
            for(int j = i-1;j>=i/2;j--)
            {
                int p1 = max(j,dp[j]);
                int p2 = max(i-j,dp[i-j]);
                dp[i] = max(dp[i],p1*p2);
            }
        }
        return dp[n];
    }
};
