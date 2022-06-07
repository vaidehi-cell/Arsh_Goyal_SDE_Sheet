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
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(!head)
            return head;
        while(head && head->val == val)
            head = head->next;
        if(head)
        {
            ListNode* curr = head->next, *prev = head;
            while(curr)
            {
                if(curr->val == val)
                    prev->next = curr->next;
                else
                    prev = prev->next;
                curr = curr->next;
            }
        }
        return head;
    }
};
