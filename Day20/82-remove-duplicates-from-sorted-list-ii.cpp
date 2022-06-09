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
        if(!head || !head->next)
            return head;
        ListNode *tmp = new ListNode(0);
        tmp->next = head;
        ListNode* prev = tmp;
        while(head)
        { 
            if(head->next && head->next->val == head->val)
            {
                while(head->next && head->next->val == head->val)
                    head = head->next;
                prev->next = head->next;
            }
            else
                prev = prev->next;
            head = head->next;
        }
        return tmp->next;
    }
};
