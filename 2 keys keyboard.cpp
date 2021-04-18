/*
Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
 

Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

Example 1:

Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
 

Note:

The n will be in the range [1, 1000].
*/
class Solution {
public:
    int dp[1001][1001];
    int minSteps(int n) {
        if(n==1)
            return 0;
        memset(dp,-1,sizeof(dp));
        return helper(1,1,1,n);
    }
    int helper(int steps,int val,int copy,int &n)
    {
        if(val>n)
            return INT_MAX;
        if(val==n)
            return steps;
        if(dp[steps][val]!=-1) return dp[steps][val];
        
        return dp[steps][val] = min(helper(steps+1,val+copy,copy,n),helper(steps+2,2*val,val,n));
    }
};

