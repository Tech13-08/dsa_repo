/*
155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/
// CODE

class MinStackElement {
    public:
        MinStackElement* next;
        int val;
        int min;
        MinStackElement(int newVal){
            this->val = newVal;
            this->next = nullptr;
            this->min = newVal;
        }
};
class MinStack {
public:
    MinStackElement* head;
    MinStack() {
        this->head = nullptr;
    }
    
    void push(int val) {
        MinStackElement* newVal = new MinStackElement(val);
        newVal->next = this->head;
        if (this->head && newVal->val > this->head->min){
            newVal->min = this->head->min;
        }
        this->head = newVal;
    }
    
    void pop() {
        MinStackElement* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
    
    int top() {
        return this->head->val;
    }
    
    int getMin() {
        return this->head->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */