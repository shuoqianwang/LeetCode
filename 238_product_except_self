class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out;
        out.push_back(1);
        for (int i = 1; i < nums.size(); i++)
            out.push_back(out.back() * nums[i - 1]);
        int c = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            c *= nums[i + 1];
            out[i] *= c;
        }
        return out;
    }
};
