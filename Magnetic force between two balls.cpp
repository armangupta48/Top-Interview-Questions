/*
In universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.

 

Example 1:


Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
Example 2:

Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.
 

Constraints:

n == position.length
2 <= n <= 10^5
1 <= position[i] <= 10^9
All integers in position are distinct.
2 <= m <= position.length
*/
class Solution {
public:
    bool isvalid(vector<int>& pos,int gap,int m)
    {
        int count =1;
        int prev = pos[0];
        for(int i = 1;i<pos.size();i++)
        {
            if(pos[i]-prev>=gap)
            {
                count++;
                prev = pos[i];
                if(count == m) return true;
            }
            
        }
    
        return false;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int st = 0;
        int ans = 0;
        int n = pos.size();
        int en = pos[n-1];
        while(st<=en)
        {
            int mid = st + (en-st)/2;
            
            if(isvalid(pos,mid,m)) 
            {
                ans = mid;
                st = mid+1;
            }
            else
                en = mid-1;
        }
        return ans;
    }
};
