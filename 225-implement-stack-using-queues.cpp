class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    int size;
    MyStack() {
        size = 0;
    }
    
    void push(int x) {
        q1.push(x);
        size++;
        while(q2.size())
        {
            q1.push(q2.front());
            q2.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
    
    int pop() 
    {
        if(q2.empty())
            return -1;
        int x = q2.front();
        q2.pop();
        size--;
        return x;
    }
    
    int top() {
        if(q2.empty())
            return -1;
        return q2.front();
    }
    
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
