class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row check

        for(int i=0;i<9;i++)
        {
            unordered_set<char>row,col;
            for(int j=0;j<9;j++)
            {
            
                if(board[i][j]!='.')
                {
                    if(row.find(board[i][j])!=row.end())
                    return false;
                    row.insert(board[i][j]);
                }
                if(board[j][i]!='.')
                {
                    if(col.find(board[j][i])!=col.end())
                    return false;
                    col.insert(board[j][i]);
                }

                
            }
             
        }

       
        // check 3*3 box

        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                unordered_set<char> boxSet;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char val = board[boxRow + i][boxCol + j];
                        if (val != '.') {
                            if (boxSet.find(val) != boxSet.end())
                                return false;
                            boxSet.insert(val);
                        }
                    }
                }
            }
        }
        return true;

    }
};
