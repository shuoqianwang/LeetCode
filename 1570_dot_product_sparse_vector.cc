class SparseVector {
public:
    map<int, int> omap;
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                this->omap.insert(make_pair(i, nums[i]));
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum = 0;
        for (auto it = this->omap.begin(); it != this->omap.end(); it++) {
            auto ptr = vec.omap.find(it->first);
            if (ptr != vec.omap.end())
                sum += it->second * ptr->second;
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
