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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* f = head->next;
        ListNode* s = head;
        while(f)
        {
            if(f->val == s->val)
            {
                f = f->next;
                s->next = f;
            }
            else
            {
                s = f;
                f = f->next;
            }
        }
        return head;
    }
};
