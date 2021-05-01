/*
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example 1:


Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
Example 2:


Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.
*/

class Solution {
public:
    vector<string> res;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<vector<int>>> strt(26);
        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0;j<board[0].size();j++)
            {
                strt[board[i][j]-'a'].push_back({i,j});
            }
        }
        for(string word:words)
        {
            char lastl = word.back();
            for(auto x:strt[lastl-'a'])
            {
                bool found = false;
                helper(x[0],x[1],word,board,found);
                if(found==true)
                {
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
    
    void helper(int x, int y, string word, vector<vector<char>> &board, bool &found)     {
        if (word.empty()) {
            found = true;
            return;
        }
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == '*' || word.back() != board[x][y]) {
            return;
        }
        char prevLetter = board[x][y];
        word.pop_back();
        board[x][y] = '*';
        helper(x + 1, y, word, board, found);
        helper(x - 1, y, word, board, found);
        helper(x, y + 1, word, board, found);
        helper(x, y - 1, word, board, found);
        // Backtracking
        board[x][y] = prevLetter;
    }
};


