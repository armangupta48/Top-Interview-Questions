/*
Given an array A of integers, return the length of the longest arithmetic subsequence in A.

Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 0 <= i_1 < i_2 < ... < i_k <= A.length - 1, and that a sequence B is arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < B.length - 1).

 

Example 1:

Input: A = [3,6,9,12]
Output: 4
Explanation: 
The whole array is an arithmetic sequence with steps of length = 3.
Example 2:

Input: A = [9,4,7,2,10]
Output: 3
Explanation: 
The longest arithmetic subsequence is [4,7,10].
Example 3:

Input: A = [20,1,15,3,10,5,8]
Output: 4
Explanation: 
The longest arithmetic subsequence is [20,15,10,5].
 

Constraints:

2 <= A.length <= 1000
0 <= A[i] <= 500
*/

//we create the dp array with 1001 rows, because it was given that diff bary from -500 to +500 that why we create v vector of 1001 size and then by the help of this dp created 

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) 
    {
        int n=nums.size(), ans=1;
        vector<int> v(1001,0);
        v[0]=1;
        vector<vector<int>> dp(n,v);

        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                int diff = nums[i]-nums[j]+500;
                if(dp[j][diff]==0) dp[i][diff]=2;
                else dp[i][diff] = max(dp[i][diff],1+dp[j][diff]);
                ans = max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};


