/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto dim = binaryMatrix.dimensions();
        int temp = -1, row = 0, col = dim[1] - 1;
        while (row < dim[0] && col > -1) {
            if (binaryMatrix.get(row, col) == 0) {
                row++;
            } else if (binaryMatrix.get(row, col) == 1) {
                if (col > 1 && binaryMatrix.get(row, col / 2) == 1) {
                    col /= 2;
                    temp = col;
                    continue;
                }
                temp = col;
                col--;
            }
        }
        return temp;
    }
};
