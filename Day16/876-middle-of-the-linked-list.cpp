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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head, *temp1 = head;
        if(!temp)
            return NULL;
        while(temp->next != NULL)
        {
            if(temp->next->next)
            {
                temp = temp->next;
                temp = temp->next;
                temp1 = temp1->next;
            }
            else
            {
                temp = temp->next;
                temp1 = temp1->next;
            }
        }
        return temp1;
    }
};
