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

ListNode* rearrange(ListNode* head)
{
    vector<ListNode*> v;
    while(head)
    {
        v.push_back(head);
        head = head->next;
    }
    vector<ListNode*> v2;
    for(int i = 0; i < v.size() / 2; i++)
    {
        v2.pb(v[i]);
        v2.pb(v[v.size()-1-i]);
    }
    if(v.size() % 2)
        v2.pb(v[v.size()/2]);
    head = v2[0];
    for(int i = 1; i < v2.size(); i++)
    {
        head->next = v2[i];
        head = head->next;
    }
    head->next = NULL;
    return v2[0];
}
