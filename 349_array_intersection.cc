class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty())
            return vector<int>();
        unordered_map<int, int> hash;
        for (auto it : nums1) {
            if (hash.find(it) == hash.end())
                ++hash[it];
        }
        for (auto it : nums2) {
            if (hash.find(it) != hash.end())
                ++hash[it];
        }
        vector<int> out;
        for (auto it : hash) {
            if (it.second > 1)
                out.push_back(it.first);
        }
        return out;
    }
};
