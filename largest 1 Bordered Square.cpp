/*
Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.

 

Example 1:

Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 9
Example 2:

Input: grid = [[1,1,0,0]]
Output: 1
 

Constraints:

1 <= grid.length <= 100
1 <= grid[0].length <= 100
grid[i][j] is 0 or 1
*/
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        vector<vector<int>> hb(grid.size(),vector<int>(grid[0].size(),0));
        vector<vector<int>> vb(grid.size(),vector<int>(grid[0].size(),0));
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                if(j>0)
                {
                    hb[i][j] = hb[i][j-1]; 
                }
                if(i>0) vb[i][j] = vb[i-1][j];
                
                hb[i][j]+=1;
                vb[i][j]+=1;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                int size = min(hb[i][j],vb[i][j]);
                if(size==0) continue;
                for(int k = size;k>0;k--)
                {
                    if(hb[i-k+1][j]>=k && vb[i][j-k+1]>=k)
                    {
                        ans = max(ans,k);
                    }
                }
            }
        }
        return ans*ans;
    }
};
