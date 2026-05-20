/*
QUESTION:-
You are given a stack of integers. Your task is to reverse the stack using recursion.
You may only use standard stack operations (push, pop, top/peek, isEmpty). You are not allowed to use any loop constructs or additional data structures like arrays or queues.
Your solution must modify the input stack in-place to reverse the order of its elements.

Example:

Input: stack = [4, 1, 3, 2]
Output: [2, 3, 1, 4]
*/

/*
APPROACH:
1. First, we create an insert function with arguments : stack st, and int i, for inserting i at bottom of the stack.
2. If stack is empty, push i into stack and return.
3. We pop the top element of the stack and save it in temp.
4. We recursively call the function to insert i in the now updated stack.
5. Now, we push temp back into the stack.
6. Now, in the main function, if stack is empty, return.
7. We pop the top element and save it in i.
8. Now, we recursively call the function to reverse the now updated stack.
9. Now, we insert i at the bottom of the stack by calling insert function.
10. This first empties the stack, and then while backtracking, inserts every element at bottom.
*/

//CODE:
class Solution {
public:
    void insert(stack<int> &st, int i) {
        if(st.empty()) {
            st.push(i);
            return;
        }

        int temp = st.top();
        st.pop();

        insert(st, i);

        st.push(temp);
    }
    
    void reverseStack(stack<int> &st) {
        if(st.empty()) return;

        int i = st.top();
        st.pop();
        reverseStack(st);
        insert(st, i);
    }
};

//Time Complexity : O(N^2) {inserting every element at bottom}
//Space Complexity : O(N) {recursion stack}
