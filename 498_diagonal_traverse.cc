class Solution {
public:
    void up(vector<vector<int>>& matrix, int i, int j, vector<int>& out) {
        while (i > -1 && j < matrix[0].size()) {
            out.push_back(matrix[i--][j++]);
        }
    }

    void down(vector<vector<int>>& matrix, int i, int j, vector<int>& out) {
        while (i < matrix.size() && j > -1) {
            out.push_back(matrix[i++][j--]);
        }
    }

    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> out;
        if (matrix.size() < 1) return out;
        for (int i = 0; i < matrix.size() + matrix[0].size() - 1; i++) {
            if (i % 2 == 0) {
                if (i < matrix.size()) {
                    up(matrix, i, 0, out);
                    continue;
                } else {
                    up(matrix, matrix.size() - 1, i - matrix.size() + 1, out);
                    continue;
                }
            }
            if (i % 2 == 1) {
                if (i < matrix[0].size()) {
                    down(matrix, 0, i, out);
                    continue;
                } else {
                    down(matrix, i - matrix[0].size() + 1, matrix[0].size() - 1, out);
                    continue;
                }
            }
        }
        return out;
    }
};
