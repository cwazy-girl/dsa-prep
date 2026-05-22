/*
QUESTION:-
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
All the calls to pop and top are valid.

Example:

Input : ["MyStack", "push", "push", "top", "pop", "empty"]
        [[], [1], [2], [], [], []]
Output : [null, null, null, 2, 2, false]
Explanation :
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
*/

//USING TWO QUEUES : 1

/*
APPROACH:
1. In this approach, we use two queues to implement a stack. We use the idea that we can push in one of the queues always, and when we have to pop, we empty that stack till we reach the last element and pop it.
2. To push, we directly push in q1.
3. To pop, since the last element must either be pushed in q1, or we might have popped all elements of q1, we first check if q1 is empty. If yes, then we pop all elements of q2 and push them in q1 till there's only 1 element left in q2. We pop that element.
4. If no, then we pop all elements of q1 and push them in q2 till only 1 element is left. We pop that element.
5. To check the top element, we follow the similar structure as pop. We do not pop the last element, rather push it in the alternate queue and return it's value.
6. To check if stack is empty, if both queues are empty, return true. Else, return false.
In this, pushing is easier and faster, but popping and top function takes O(N) time.
*/

//CODE:
class MyStack {
public:
    queue<int> q1, q2;

    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q1.empty()) {
            while(q2.size() != 1) {
                q1.push(q2.front());
                q2.pop();
            }
            int k = q2.front();
            q2.pop();
            return k;
        }

        while(q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int k = q1.front();
        q1.pop();
        return k;
    }
    
    int top() {
        if(q1.empty()) {
            while(q2.size() != 1) {
                q1.push(q2.front());
                q2.pop();
            }
            int k = q2.front();
            q2.pop();
            q1.push(k);
            return k;
        }

        while(q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int k = q1.front();
        q1.pop();
        q2.push(k);
        return k;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

//Time Complexity : Push - O(1), Pop - O(N), Top - O(N), Empty - O(1)
//Space Complexity : O(N)

//USING TWO QUEUES : 2

/*
APPROACH:
1. In this approach, we use two queues to implement a stack. We use the idea that our top element stay at the front of the queue. So, when we push, we push in whichever queue is empty, and then push all elements of the other queue into this queue.
2. To push, if q1 is empty, then we push x in q1, and then we pop all elements of q2 and push them in q1. Else, we push x in q2 and pop all elements of q1 and push them in q2.
3. To pop, we pop the element of whichever queue is not empty.
4. To check the top element, we return front of whichever queue is not empty.
5. To check if stack is empty, if both queues are empty, return true. Else, return false.
In this, pushing takes O(N) time while popping and top function are convenient and faster.
*/

//CODE:
class MyStack {
public:
    queue<int> q1, q2;

    MyStack() {
    }
    
    void push(int x) {
        if(q1.empty()) {
            q1.push(x);
            
            while(!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else {
            q2.push(x);
            
            while(!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }
    
    int pop() {
        if(q1.empty()) {
            int k = q2.front();
            q2.pop();
            return k;
        }
        else {
            int k = q1.front();
            q1.pop();
            return k;
        }
    }
    
    int top() {
        if(q1.empty()) {
            return q2.front();
        }
        return q1.front();
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

//In this approach, instead of using if-else everytime, we can swap q1 and q2.

//Time Complexity : Push - O(N), Pop - O(1), Top - O(1), Empty - O(1)
//Space Complexity : O(N)

//USING ONE QUEUE

/*
APPROACH:
1. In this approach, we use one queue to implement a stack. We use the idea that everytime we push, we pop the elements before it and push them back in the queue.
2. To push, we first save the current size of the queue in a variable n, and then push the element. Then, we run a loop from 0 to n-1, and pop all elements and push them back in the stack. By the end, x will be at the front of the queue.
3. To pop, we pop the front element from the queue.
4. To check the top, we return the front element of the queue.
5. To check if stack is empty, if queue is empty, return true. Else, return false.
In this, push takes O(N) time while popping and top function are convenient and faster. It also uses just one queue to implement the stack.
*/

//CODE:
class MyStack {
public:
    queue<int> q;

    MyStack() {
    }
    
    void push(int x) {
        int n = q.size();
        q.push(x);

        for(int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int k = q.front();
        q.pop();
        return k;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

//Time Complexity : Push - O(N), Pop - O(1), Top - O(1), Empty - O(1)
//Space Complexity : O(N)
