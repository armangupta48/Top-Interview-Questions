/*
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:

Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:

The number of given pairs will be in the range [1, 1000].
*/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        vector<int> dp(pairs.size(),1);
        int m = 0;
        int res = 0;
        for(int i = 1;i<pairs.size();i++)
        {
            int c = pairs[i][0];
            for(int j = 0;j<i;j++)
            {
                if(c>pairs[j][1])
                {
                    m = max(m,dp[j]);
                }
            }
            dp[i] = m+1;
            res = max(res,dp[i]);
        }
        return res;
    }
};
