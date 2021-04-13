/*
A string is called happy if it does not have any of the strings 'aaa', 'bbb' or 'ccc' as a substring.

Given three integers a, b and c, return any string s, which satisfies following conditions:

s is happy and longest possible.
s contains at most a occurrences of the letter 'a', at most b occurrences of the letter 'b' and at most c occurrences of the letter 'c'.
s will only contain 'a', 'b' and 'c' letters.
If there is no such string s return the empty string "".

 

Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

Input: a = 2, b = 2, c = 1
Output: "aabbc"
Example 3:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It's the only correct answer in this case.
 

Constraints:

0 <= a, b, c <= 100
a + b + c > 0
*/

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s = "";
        priority_queue<pair<int, char>> pq;
        if(a != 0) pq.push({ a, 'a' });
        if(b != 0) pq.push({ b, 'b' });
        if(c != 0) pq.push({ c, 'c' });
        char prev1 = '#';
        char prev2 = '#';
        while(!pq.empty())
        {
            auto [co1,ch1] = pq.top();
            pq.pop();
            if(ch1==prev2 && ch1 == prev1)
            {
                if(pq.empty()) return s;
                auto [co2,ch2] = pq.top();
                pq.pop();
                s = s+ch2;
                prev2 = prev1;
                prev1 = ch2;
                co2--;
                pq.push({co1,ch1});
                if(co2>0)
                {
                    pq.push({co2,ch2});
                }
            }
            else
            {
                s=s+ch1;
                prev2 = prev1;
                prev1 = ch1;
                co1--;
                if(co1>0)
                {
                    pq.push({co1,ch1});
                }
            }
        }
        return s;
    }
};
