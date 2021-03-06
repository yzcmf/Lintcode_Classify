/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/valid-sudoku
@Language: C++
@Datetime: 16-08-31 03:10
*/

class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        if(board.size()!=9 || board[0].size()!=9) return false;
        
        //check the row
        for(int i=0;i<9;i++)
        {
            vector<bool>used(9,false);
            for(int j=0;j<9;j++)
            {
                if(!isdigit(board[i][j])) continue;
                int k= board[i][j]-'0';
                if(k==0 || used[k-1]) return false;
                used[k-1] = true;
            }
        }
        
        //check the col
        for(int j=0;j<9;j++)
        {
            vector<bool>used(9,false);
            for(int i=0;i<9;i++)
            {
                if(!isdigit(board[i][j])) continue;
                int k= board[i][j]-'0';
                if(k==0 || used[k-1]) return false;
                used[k-1] = true;
            }
        }
        
        //check the subbox
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                int row = 3*i;
                int col = 3*j;
                vector<bool>used(9,false);
                for(int m=row;m<row+3;m++)
                {
                  for(int n=col;n<col+3;n++)
                  {
                   if(!isdigit(board[m][n])) continue;
                   int k= board[m][n]-'0';
                   if(k==0 || used[k-1]) return false;
                   used[k-1] = true;
                  }
                }  
            }
        }
        
        return true;
    }
};



//http://bangbingsyb.blogspot.com/2014/11/leetcode-valid-sudoku-sudoku-solver.html
//Also another problem in leetcode: Sudoku Solver 