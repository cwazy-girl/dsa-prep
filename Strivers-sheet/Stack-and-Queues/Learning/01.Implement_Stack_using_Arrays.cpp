/*
QUESTION:-
Implement a Last-In-First-Out (LIFO) stack using an array. The implemented stack should support the following operations: push, pop, peek, and isEmpty.

Example:

Input: ["mystack", "push", "push", "peek", "pop", "isEmpty"]
       [[], [5], [10], [], [], []]
Output: [null, null, null, 10, null, false]
Explanation: 
mystack stack = new mystack();
stack.push(5);
stack.push(10);
stack.peek(); // returns 10
stack.pop();
stack.isEmpty(); // returns false
*/

/*
APPROACH:
1. To implement stack using array, we need an array, and top variable.
2. To push, we move top to the next index, and add the element there. If top is already at its max limit, it gives stack overflow.
3. To pop, we pop out the element at top, and then move top to the previous index. If top is at -1, it gives stack underflow.
4. To peek, we return the element at top. If top is at -1, it gives stack underflow.
5. For isEmpty, if top = -1, that means our stack is empty. Return true. Else, return false.
*/

//CODE:
struct mystack {
    int top;
    int size;
    int* arr;

    mystack(int n) {
        top = -1;
        size = n;
        arr = new int[size];
    }

    void push(int x) {
        if (top + 1 == size) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into stack." << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << arr[top--] << " popped from stack." << endl;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        cout << arr[top] << " is at the top." << endl;
        return arr[top];
    }

    bool isEmpty() {
        if (top == -1) {
            cout << "Stack empty" << endl;
            return true;
        }
        cout << "Stack not empty" << endl;
        return false;
    }
};

//Time Complexity : O(1) {since we use top}
//Space Complexity : O(N) {array}
