/*
QUESTION:-
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:
1. MinStack() initializes the stack object.
2. void push(int val) pushes the element val onto the stack.
3. void pop() removes the element on the top of the stack.
4. int top() gets the top element of the stack.
5. int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example:

Input : ["MinStack","push","push","push","getMin","pop","top","getMin"]
        [[],[-2],[0],[-3],[],[],[],[]]
Output : [null,null,null,null,-3,null,0,-2]
Explanation:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/

//USING TWO STACKS:

/*
APPROACH:
1. In this approach, we use two stacks to implement a minstack : One stack holds the values of elements, while the other holds the min element.
2. To push, we push val to s1. Then, we check if s2 is empty or its top is greater than val {that means our current val is lesser than previous min}. If yes, we push val in s2.
3. To pop, we pop the top element from s1. If that value is equal to top value of s2 {min value}, that means we have to remove that min value. Hence, pop from s2 also.
4. To get the top value of minstack, return s1.top().
5. To get the min value of minstack, return s2.top().
*/

//CODE:
class MinStack {
public:
    stack<int> s1;
    stack<int> s2;

    MinStack() {
    }
    
    void push(int val) {
        if(s2.empty() || val <= s2.top()) {
            s2.push(val);
        }

        s1.push(val);
    }
    
    void pop() {
        if(s1.top() == s2.top()) s2.pop();
        
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

//Time Complexity : O(1) {for all}
//Space Complexity : O(N) {extra space}

//USING ONE STACK:

/*
APPROACH:
1. In this approach, we use a single stack and a variable to implement a minstack : stack containing long long values, and mini variable.
2. To push, if stack is empty, we push val in stack and update mini to val. Else if value is greater than or equal to mini, push value in stack.
3. Else when val is less than mini, we push [2*val - mini] into stack {since it is then always lesser than mini and can help us access the previous mini} and update mini to val. {2LL is used to force 64 bit arithmetic.}
4. To pop, we pop the top element from stack. If that element is lesser than mini, that means we need to update mini back to previous mini. So, we update mini to 2*mini - st.top() {since st.top() has 2*val - mini as value}.
5. To get the top value of minstack, if top element of stack is lesser than mini, return mini. Else, return st.top().
6. To get the min value of minstack, return mini.
*/

//CODE:
class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            mini = val;
        }
        else if(val >= mini) st.push(val);
        else {
            st.push(2LL * val - mini);
            mini = val;
        }
    }
    
    void pop() {
        if(st.top() < mini) {
            mini = (2LL * mini) - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < mini) return mini;
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};

//Time Complexity : O(1) {for all}
//Space Complexity : O(1) {no extra space}

//An alternate solution proposes use of a stack containing pairs as it's elements. Each element contains the value, and the minimum uptil there.
