class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string str = "";
        string s1 = strs[0];
        if(strs.size()==1)
            return s1;
        int ml =INT_MAX;
        for(int i =1;i<strs.size();i++)
        {
            int j = 0;
            string s2 = strs[i];
            while(j<s1.size() && j<s2.size() && s1[j]==s2[j])
            {
                j++;
            }
            string ans = s1.substr(0,j);
            s1 = ans;
        }
       
        return s1;
    }
};
