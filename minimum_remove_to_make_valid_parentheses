class Solution {
public:
    string minRemoveToMakeValid(string s) {
        set<int> indexToRemove;
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
                continue;
            }
            if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    indexToRemove.insert(i);
                }
            }
        }
        while (!st.empty()) {
            indexToRemove.insert(st.top());
            st.pop();
        }
        std::string str;
        int start = 0;
        for (auto it = indexToRemove.begin(); it != indexToRemove.end(); it++) {
            if (start < *it) {
                str.append(s.substr(start, *it - start));
                start = *it + 1;
                continue;
            }
            if (start == *it) {
                start++;
            }
        }
        if (start < s.size())
            str.append(s.substr(start));
        return str;
    }
};
