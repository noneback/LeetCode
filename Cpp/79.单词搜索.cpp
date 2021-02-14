/**
	DFS
**/

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int index) {
        if (index == word.length()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '*' || board[i][j] != word[index]) return false;

        char ch = board[i][j];
        board[i][j] = '*';
        bool ret = dfs(board,word,i,j - 1,index + 1) || dfs(board,word,i,j + 1,index + 1) ||
                   dfs(board,word,i - 1,j,index + 1) || dfs(board,word,i + 1,j,index + 1);
        board[i][j] = ch;
        
        return ret;
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool ret = false;
        for (int i = 0;i < board.size();i++) {
            for (int j = 0;j < board[0].size();j++) {
                if (board[i][j] == word[0]) {
                    ret = ret || dfs(board, word, i, j, 0);
                }
            }
        }
        return ret;

    }
};
