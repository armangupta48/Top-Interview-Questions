/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int l = 0,r = n-1,t=0,b=n-1,d=0;
        vector<vector<int>> ans(n,vector<int>(n,0));
        int val = 1;
        while(l<=r && t<=b)
        {
            if(d==0)
            {
                for(int i = l;i<=r;i++)
                {
                    ans[t][i] = val;
                    val++;
                }
                d=1;
                t++;
            }
            else if(d==1)
            {
                for(int i=t;i<=b;i++)
                {
                    ans[i][r] = val;
                    val++;
                }
                r--;
                d=2;
            }
            else if(d==2)
            {
                for(int i = r;i>=l;i--)
                {
                    ans[b][i]=val;
                    val++;
                }
                d=3;
                b--;
            }
            else if(d==3)
            {
                for(int i = b;i>=t;i--)
                {
                    ans[i][l] = val;
                    val++;
                }
                d=0;
                l++;
            }
        }
        return ans;
    }
};
