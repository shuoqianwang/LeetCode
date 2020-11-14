/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int out = 0;
        unordered_map<int, Employee*> dict;
        for (auto it : employees) {
            dict.insert(make_pair(it->id, it));
        }
        queue<int> buffer;
        buffer.push(id);
        while (!buffer.empty()) {
            int id = buffer.front();
            buffer.pop();
            auto ptr = dict.find(id);
            if (ptr != dict.end()) {
                out += ptr->second->importance;
                if (!ptr->second->subordinates.empty()) {
                    for (auto it : ptr->second->subordinates) {
                        buffer.push(it);
                    }
                }
            }
        }
        return out;
    }
};
