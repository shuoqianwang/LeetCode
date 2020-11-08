/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <int, vector<int>, greater<int>> pq_min;
        for (auto it : lists) {
            ListNode* temp = it;
            while (temp != nullptr) {
                pq_min.push(temp->val);
                temp = temp->next;
            }
        }
        ListNode* out = new ListNode();
        ListNode* temp = out;
        while (!pq_min.empty()) {
            temp->next = new ListNode(pq_min.top());
            temp = temp->next;
            pq_min.pop();
        }
        return out->next;
    }
};
