/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
 

Follow up: Could you solve it using only O(s2.length) additional memory space?
*/

class Solution {
public:
    int dp[101][101];
    bool helper(string s1,int i,string s2,int j,string s3,int k)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==s1.size() && j==s2.size() && k == s3.size()) return dp[i][j] = true;
        bool ans = false;
        if(i!=s1.size())
        {
            if(s1[i] == s3[k]) 
                ans = ans || helper(s1,i+1,s2,j,s3,k+1);
        }
        if(j!=s2.size())
        {
            if(s2[j] == s3[k]) 
                ans = ans || helper(s1,i,s2,j+1,s3,k+1);
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        memset(dp,-1,sizeof dp);
       return helper(s1,0,s2,0,s3,0);
    }
};
