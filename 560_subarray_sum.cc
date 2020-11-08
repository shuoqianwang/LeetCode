class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> umap;
        umap.insert(make_pair(0, 1));
        for (auto it = nums.begin(); it != nums.end(); it++) {
            sum += *it;
            auto itr = umap.find(sum - k);
            if (itr != umap.end())
                count += itr->second;
            // to avoid k == 0, insert(sum) must behind find(sum - k)
            itr = umap.find(sum);
            if (itr != umap.end())
                itr->second++;
            else umap.insert(make_pair(sum, 1));
        }
        return count;
    }
};
