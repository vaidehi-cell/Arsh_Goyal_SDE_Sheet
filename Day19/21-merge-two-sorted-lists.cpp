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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode* ans = NULL;
        if(list1->val <= list2->val)
        {
            ans = list1;
            list1 = list1->next;
        }
        else
        {
            ans = list2;
            list2 = list2->next;
        }
        ListNode * tmp = ans;
        while(list1 || list2)
        {
            if(list1 && list2)
            {
                if(list1->val <= list2->val)
                {
                    ans->next = list1;
                    ans = ans->next;
                    list1 = list1->next;
                }
                else
                {
                    ans->next = list2;
                    ans = ans->next;
                    list2 = list2->next;
                }
            }
            else if(list1)
            {
                ans->next = list1;
                ans = ans->next;
                list1 = list1->next;
            }
            else if(list2)
            {
                ans->next = list2;
                ans = ans->next;
                list2 = list2->next;
            }
        }
        return tmp;
    }
};
