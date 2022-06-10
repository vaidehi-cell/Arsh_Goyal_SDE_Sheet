class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int value)
    {
        val = value;
        next = NULL;
    }
};

ListNode* segregate(ListNode* head)
{
    ListNode *evenHead = new ListNode(0), *even = evenHead;
    ListNode *oddHead = new ListNode(0), *odd = oddHead;
    while(head)
    {
        if(head->val % 2)
        {
            odd->next = head;
            odd = odd->next;
        }
        else
        {
            even->next = head;
            even = even->next;
        }
        head = head->next;
    }
    even->next = oddHead->next;
    return evenHead->next;
}
