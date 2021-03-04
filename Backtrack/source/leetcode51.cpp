class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> track(n, string(n, '.'));
        backtrack(res, track, 0);
        return res;
    }

    bool isValid(vector<string> track, int row, int col){
        int n = track.size();
        for(int i = 0; i < n; ++i){
            if(track[i][col] == 'Q')
                return false;
        }

        for(int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j){
            if(track[i][j] == 'Q')
                return false;
        }

        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j){
            if(track[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void backtrack(vector<vector<string>>& res, vector<string>& track, int row){
        if(row == track.size()){
            res.push_back(track);
            return;
        }
        for(int col = 0; col < track.size(); ++col){
            if(isValid(track, row, col)){
                track[row][col] = 'Q';
                backtrack(res, track, row + 1);
                track[row][col] = '.';
            }
        }
        return;
    }
};