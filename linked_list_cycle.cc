/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode* ptr = head->next;
        int len = 0;
        while (len > -1 && ptr != NULL) {
            int tmp = (int)(ptr - head);
            ptr = ptr->next;
            len = tmp > len ? tmp : -1;
        }
        return len == -1 ? true : false;
    }
};
