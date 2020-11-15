class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return true;
        map<int, int> bst;
        for (auto it : intervals) {
            bst.insert(make_pair(it[0], it[1]));
        }
        if (bst.size() < intervals.size())
            return false;
        int last = bst.begin()->second;
        for (auto it = next(bst.begin()); it != bst.end(); it++) {
            if (it->first < last)
                return false;
            last = it->second;
        }
        return true;
    }
};
