class Solution {
public:
    int dist(vector<int>& point) {
        int sum = 0;
        for (auto p : point)
            sum += p * p;
        return sum;
    }
    
    int partition(vector<vector<int>>& points, int start, int end, int pivot_i) {
        int pivot = dist(points[pivot_i]);
        swap(points[pivot_i], points[end]);
        int flag = start;
        for (int i = start; i < end; i++) {
            if (dist(points[i]) < pivot) {
                if (i != flag)
                    swap(points[i], points[flag]);
                flag++;
            }
        }
        swap(points[flag], points[end]);
        return flag;
    }
    
    void quicksort(vector<vector<int>>& points, int start, int end, int K) {
        if (start == end)
            return;
        int pivot_i = start + rand() % (end - start);
        pivot_i = partition(points, start, end, pivot_i);
        if (pivot_i == K)
            return;
        else if (pivot_i > K)
            quicksort(points, start, pivot_i - 1, K);
        else quicksort(points, pivot_i + 1, end, K);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> select;
        if (K < points.size())
            quicksort(points, 0, points.size() - 1, K);
        else return points;
        for (int i = 0; i < K; i++)
            select.push_back(points[i]);
        return select;
    }
};
