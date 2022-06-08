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
    ListNode* partition(ListNode* head, int x) {
        ListNode *before1 = new ListNode(0), *after1 = new ListNode(0);
        ListNode *before = before1, *after = after1;
        while(head)
        {
            if(head->val < x)
            {
                before->next = head;
                before = before->next;
            }
            else
            {
                after->next = head;
                after = after->next;
            }
            head = head->next;                
        }
        after->next = NULL;
        before->next = after1->next;
        return before1->next;
    }
};
