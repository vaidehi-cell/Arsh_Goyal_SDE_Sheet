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
class Solution 
{
public:
     ListNode* merge(ListNode* list1, ListNode* list2) 
     {
        if(!list1) 
            return list2;
        if(!list2)
            return list1;
        if(list1->val < list2->val) 
        {
            list1->next = merge(list1->next, list2);
            return list1;
        }
        else 
        {
            list2->next = merge(list1, list2->next);
            return list2;
        }
    }
    
    ListNode* mergeSort(ListNode* head)
    {
        if(!head || !head->next)
            return head;
        
        ListNode* temp = NULL;
        ListNode* slow = head, *fast = head;
        while(fast && fast->next) 
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;  
        ListNode* l1 = mergeSort(head);
        ListNode* l2 = mergeSort(slow); 
        return merge(l1, l2); 
    }
    
    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        return mergeSort(head);         
    }
};
