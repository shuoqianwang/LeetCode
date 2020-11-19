class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), [](vector<int>& first, vector<int>& second) { // pass by ref is much faster
            return first[0] < second[0];
        });
        auto ptr1 = intervals.begin(),
             ptr2 = intervals.begin() + 1;
        vector<vector<int>> out;
        while (ptr2 != intervals.end()) {
            if ((*ptr1)[1] < (*ptr2)[0]) {
                out.push_back(*ptr1);
                ptr1 = ptr2;
            } else {
                (*ptr1)[1] = max((*ptr1)[1], (*ptr2)[1]);
            }
            ++ptr2;
        }
        out.push_back(*ptr1);
        return out;
    }
};
