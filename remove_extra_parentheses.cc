class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> index2rm;
        stack<int> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                stk.push(i);
            else if (s[i] == ')') {
                if (!stk.empty())
                    stk.pop();
                else index2rm.push_back(i);
            }
        }
        while (!stk.empty()) {
            index2rm.push_back(stk.top());
            stk.pop();
        }
        string str;
        int start = 0;
        sort(index2rm.begin(), index2rm.end(), less<int>());
        for (auto it = index2rm.begin(); it != index2rm.end(); it++) {
            if (start < *it) {
                str.append(s.substr(start, *it - start));
                start = *it + 1;
                continue;
            } else if (start == *it)
                start++;
        }
        if (start < s.size())
            str.append(s.substr(start));
        return str;
    }
};
