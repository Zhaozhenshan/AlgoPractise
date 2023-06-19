#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

private:
    int rows;
    int cols;
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int k)
    {
        //1. 定义递归出口
        if (i < 0 || i >= rows || j < 0 || j >= cols || (board[i][j] != word[k]))
            return false;
        if (k == word.size() - 1)
            return true; //如果k=word.size()-1，说明已经完全验证过了
        //2. 递归前保护现场，该点已经遍历过，应该为空，防止多次遍历同一个位置
        board[i][j] = '\0';
        bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) || dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
        //3. 递归后恢复现场
        board[i][j] = word[k];
        return res;
    }
};