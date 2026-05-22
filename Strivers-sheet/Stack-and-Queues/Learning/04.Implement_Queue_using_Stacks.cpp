/*
QUESTION:-
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
All the calls to pop and peek are valid.

Example:

Input : ["MyQueue", "push", "push", "peek", "pop", "empty"]
        [[], [1], [2], [], [], []]
Output : [null, null, null, 1, 1, false]
Explanation :
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
*/

/*
APPROACH:
1. We use the idea that we always push in one stack, and whenever we have to pop, we use the other stack.
2. To push, we push the element in s1.
3. To pop, if s2 is empty, we pop all elements out of s1 and push them in s2.
4. Then, we pop the element out of s2. {This way, the last element comes to the top, hence acting like a queue.}
5. To peek, if s2 is empty, we pop all elements out of s1 and push them in s2. Then, we return the top element of s2.
6. To check if queue is empty, if both stacks are empty, return true. Else, return false.
*/

//CODE:
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()) {
            while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
            }
        }
        int k = s2.top();
        s2.pop();
        return k;
    }
    
    int peek() {
        if(s2.empty()) {
            while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

//Time Complexity : Push - O(1), Pop - O(N), Top - O(N), Empty - O(1) {because transfer may occur}
//Amortized Complexity {average cost per operation} : O(1) {for all}
//Space Complexity : O(N)
