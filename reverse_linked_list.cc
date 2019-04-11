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
