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
        vector<int> dim = binaryMatrix.dimensions();
        int temp = -1, r = 0, c = dim[1] - 1;
        while (r < dim[0] && c > -1) {
            if (binaryMatrix.get(r, c) == 1) {
                temp = c;
                c--;
            } else if (binaryMatrix.get(r, c) == 0) {
                r++;
            }
        }
        return temp;
    }
};
