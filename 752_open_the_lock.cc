class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> hash;
        for (auto it : deadends)
            hash.insert(it);
        queue<string> q;
        q.push("0000");
        q.push("");
        unordered_set<string> visit;
        visit.insert("0000");
        int count = 0;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            if (cur == "" && !q.empty()) {
                count++;
                q.push("");
                continue;
            }
            if (cur == target)
                return count;
            if (hash.find(cur) != hash.end())
                continue;
            for (int i = 0; i < target.size(); i++) {
                cur[i] = '0' + (cur[i] - '0' + 1) % 10;
                if (visit.find(cur) == visit.end()) {
                    visit.insert(cur);
                    q.push(cur);
                }
                cur[i] = '0' + (cur[i] - '0' + 8) % 10;
                if (visit.find(cur) == visit.end()) {
                    visit.insert(cur);
                    q.push(cur);
                }
                cur[i] = '0' + (cur[i] - '0' + 1) % 10;
            }
        }
        return -1;
    }
};
