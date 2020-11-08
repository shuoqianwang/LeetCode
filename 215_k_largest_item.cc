class Solution {
public:
    int partition(vector<int>& nums, int start, int end, int pivot_i) {
        int pivot = nums[pivot_i];
        swap(nums[pivot_i], nums[end]);
        int flag = start;
        for (int i = start; i < end; i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[flag]);
                flag++;
            }
        }
        swap(nums[flag], nums[end]);
        return flag;
    }
    
    int quicksort(vector<int>& nums, int start, int end, int k) {
        if (start == end)
            return nums[start];
        int pivot_i = start + rand() % (end - start);
        pivot_i = partition(nums, start, end, pivot_i);
        if (k == pivot_i)
            return nums[k];
        else if (k < pivot_i)
            return quicksort(nums, start, pivot_i - 1, k);
        else return quicksort(nums, pivot_i + 1, end, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return quicksort(nums, 0, nums.size() - 1, nums.size() - k);
    }
};
