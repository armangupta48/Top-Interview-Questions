5. Longest Palindromic Substring
Medium

10117

665

Add to List

Share
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n));
        int a =0,b=0;
        for(int g = 0;g<n;g++)
        {
            for(int i = 0,j=g;j<n;i++,j++)
            {
                if(g==0)
                {
                    dp[i][j]=true;
                }
                else if(g==1)
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=true;

                    }
                    else
                        dp[i][j]=false;
                }
                else
                {
                    if(s[i]==s[j] && dp[i+1][j-1]==true)
                    {
                        dp[i][j]=true;
  
                    }
                    else
                        dp[i][j]=false;
                }
                if(dp[i][j]==true)
                {
                    a= i;
                b= j;
                }
            }
        }
        return s.substr(a,b-a+1);
    }
};
