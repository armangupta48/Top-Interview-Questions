/*
You are given a 2D matrix of size m x n, consisting of non-negative integers. You are also given an integer k.

The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j] where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).

Find the kth largest value (1-indexed) of all the coordinates of matrix.

 

Example 1:

Input: matrix = [[5,2],[1,6]], k = 1
Output: 7
Explanation: The value of coordinate (0,1) is 5 XOR 2 = 7, which is the largest value.
Example 2:

Input: matrix = [[5,2],[1,6]], k = 2
Output: 5
Explanation: The value of coordinate (0,0) is 5 = 5, which is the 2nd largest value.
Example 3:

Input: matrix = [[5,2],[1,6]], k = 3
Output: 4
Explanation: The value of coordinate (1,0) is 5 XOR 1 = 4, which is the 3rd largest value.
Example 4:

Input: matrix = [[5,2],[1,6]], k = 4
Output: 0
Explanation: The value of coordinate (1,1) is 5 XOR 2 XOR 1 XOR 6 = 0, which is the 4th largest value.
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
0 <= matrix[i][j] <= 106
1 <= k <= m * n
*/

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        map<int,int> mp;
        for(int i=0;i<matrix.size();i++)
            for(int j=1;j<matrix[0].size();j++)
                matrix[i][j]=(matrix[i][j]^matrix[i][j-1]);
            
        for(int i=0;i<matrix[0].size();i++)
            for(int j=1;j<matrix.size();j++)
                matrix[j][i]=(matrix[j][i]^matrix[j-1][i]);
        
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                mp[matrix[i][j]]++;
            }
        }
        vector<pair<int,int>> v;
        for(auto x: mp)
            v.push_back({x.first,x.second});
        
        sort(v.rbegin(),v.rend());
        for(auto x:v)
        {
            cout<<x.first<<" "<<x.second<<endl;
        }
        int a =0;
        for(auto x:v)
        {
            a+=x.second;
            if(a>=k)
                return x.first;
        }
        
        return 0;
    }
};
