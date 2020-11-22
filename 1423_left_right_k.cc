class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> left(k + 1, 0), right(k + 1, 0);
        for (int i = 1; i <= k; ++i) {
            left[i] = left[i - 1] + cardPoints[i - 1];
            right[i] = right[i - 1] + cardPoints[cardPoints.size() - i];
        }
        int out = 0;
        for (int i = 0; i <= k; ++i) {
            out = max(out, left[i] + right[k - i]);
        }
        return out;
    }
};
