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
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr = NULL;
        ListNode* tmp = head;
        while (tmp != NULL) {
            ListNode* nextTmp = tmp->next;
            tmp->next = ptr;
            ptr = tmp;
            tmp = nextTmp;
        }
        return ptr;
    }
};
