/*
Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

 

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 

Constraints:

1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 105
*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n =  s.size();
        if(k <=1)return n;
        if(n==0 || n<k) return 0; 
        map<char,int> m;
        for(int i = 0;i<n;i++)
        {
            m[s[i]]++;
        }
        int l = 0;
        while(l<n && m[s[l]]>=k) l++;
        if(l==n) return l;
        int l1 = longestSubstring(s.substr(0,l),k);
        while(l<n && m[s[l]]<k) l++;
        int l2 = (l<n)?longestSubstring(s.substr(l),k):0;
        
        return max(l1,l2);
    }
};
