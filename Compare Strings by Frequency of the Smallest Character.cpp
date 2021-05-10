/*
Let the function f(s) be the frequency of the lexicographically smallest character in a non-empty string s. For example, if s = "dcce" then f(s) = 2 because the lexicographically smallest character is 'c', which has a frequency of 2.

You are given an array of strings words and another array of query strings queries. For each query queries[i], count the number of words in words such that f(queries[i]) < f(W) for each W in words.

Return an integer array answer, where each answer[i] is the answer to the ith query.

 

Example 1:

Input: queries = ["cbd"], words = ["zaaaz"]
Output: [1]
Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").
Example 2:

Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
Output: [1,2]
Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").
 

Constraints:

1 <= queries.length <= 2000
1 <= words.length <= 2000
1 <= queries[i].length, words[i].length <= 10
queries[i][j], words[i][j] consist of lowercase English letters.
*/

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> t;
        vector<int> ans;
        for(string x:queries)
        {
            sort(x.begin(),x.end());
            char a = x[0];
            int count = 0;
            int i = 0;
            while(x[i]==a)
            {
                i++;
                count++;
            }
            t.push_back(count);
        }
        vector<int> t1;
        for(string x:words)
        {
            sort(x.begin(),x.end());
            char a = x[0];
            int count = 0;
            int i = 0;
            while(x[i]==a)
            {
                i++;
                count++;
            }
            t1.push_back(count);
        }
        int n = t1.size();
        sort(t1.begin(),t1.end());
        for(int i = 0;i<t.size();i++)
        {
            auto ub = upper_bound(t1.begin(),t1.end(),t[i]);
            if(ub-t1.begin()==0)
            {
                ans.push_back(n);
            }
            else
                ans.push_back(n-(ub-t1.begin()));
        }
        return ans;
    }
};
