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
    bool isPalindrome(ListNode* head) {
        vector<int> check;
        while(head)
        {
            check.push_back(head->val);
            head = head->next;
        }
        for(int i = 0; i < check.size()/2; i++)
        {
            if(check[i] != check[check.size()-1-i])
                return false;
        }
        return true;
    }
};
