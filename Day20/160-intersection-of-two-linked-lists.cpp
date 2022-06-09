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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *temp1 = headA, *temp2 = headB;
        int a = 0, b = 0;
        while(temp1)
        {
            a++;
            temp1 = temp1->next;
        }
        while(temp2)
        {
            b++;
            temp2 = temp2->next;
        }
        temp1 = headA, temp2 = headB;
        while(a != b)
        {
            if(a > b)
            {
                a--;
                temp1 = temp1->next;
            }
            else
            {
                b--;
                temp2 = temp2->next;
            }
        }
        while(temp1 != temp2 && temp1)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
};
