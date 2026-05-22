/*
QUESTION:-
Implement a First-In-First-Out (FIFO) queue using an array. The implemented queue should support the following operations: push, pop, peek, and isEmpty.

Example:

Input: ["myqueue", "push", "push", "peek", "pop", "isEmpty"]
       [[], [5], [10], [], [], []]
Output: [null, null, null, 5, null, false]
Explanation:
myqueue queue = new myqueue();
queue.push(5);
queue.push(10);
queue.peek(); // returns 5
queue.pop();
queue.isEmpty(); // returns false
*/

//LINEAR QUEUE

/*
APPROACH:
1. To implement a queue using array, we need an array, and front and rear variables. Front will help in popping the element, and rear will help in pushing the element.
2. To push, we move rear to the next index, and add an element there. If rear is already at it's max limit, it gives queue overflow.
3. To pop, we pop out the element at front and move front to the next index. If front > rear, it gives queue underflow.
4. To peek, we return the element at front. If front > rear, it gives queue underflow and returns -1.
5. For isEmpty, if front > rear, that means our queue is empty. Return true. Else, return false.
*/

//CODE:
struct myqueue {
    int front;
    int rear;
    int size;
    int* arr;

    myqueue(int n) {
        front = 0;
        rear = -1;
        size = n;
        arr = new int[n];
    }

    void push(int x) {
        if (rear + 1 == size) {
            cout << "Queue Overflow" << endl;
            return;
        }
        arr[++rear] = x;
        cout << x << " pushed into queue." << endl;
    }

    void pop() {
        if (front > rear) {
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << arr[front++] << " popped from queue" << endl;
    }

    int peek() {
        if (front > rear) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        cout << arr[front] << " is at the front." << endl;
        return arr[front];
    }

    bool isEmpty() {
        if (front > rear) {
            cout << "Queue empty" << endl;
            return true;
        }
        cout << "Queue not empty" << endl;
        return false;
    }
};

//Time Complexity : O(1) {due to front and rear}
//Space Complexity : O(N) {array}

//CIRCULAR QUEUE

/*
APPROACH:
1. In this implementation, front represents the first element in the queue, and rear represents the next empty space to push an element.
2. To push, we add an element to rear, and update rear to (rear+1) % size. If (rear+1) % size is front, that means our queue is full. So, it gives queue overflow.
3. We leave the space empty at rear in overflow because otherwise, the condition for both empty and full queue will be front == rear. So, to distinguish, one space is left empty.
4. To pop, we pop the element at front, update front to (front+1) % size. If front == rear, it means our queue is empty. It gives queue underflow.
5. To peek, we return the element at front. If front == rear, it gives queue underflow and returns -1.
6. For isEmpty, if front == rear, that means our queue is empty. Return true. Else, return false.
*/

//CODE:
struct myqueue {
    int front;
    int rear;
    int size;
    int* arr;

    myqueue(int n) {
        front = 0;
        rear = 0;
        size = n;
        arr = new int[n];
    }

    void push(int x) {
        if ((rear + 1) % size == front) {
            cout << "Queue Overflow" << endl;
            return;
        }
        arr[rear] = x;
        rear = (rear + 1) % size;
        cout << x << " pushed into queue." << endl;
    }

    void pop() {
        if (front == rear) {
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << arr[front] << " popped from queue" << endl;
        front = (front + 1) %  size;
    }

    int peek() {
        if (front == rear) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        cout << arr[front] << " is at the front." << endl;
        return arr[front];
    }

    bool isEmpty() {
        if (front == rear) {
            cout << "Queue empty" << endl;
            return true;
        }
        cout << "Queue not empty" << endl;
        return false;
    }
};

//Time Complexity : O(1)
//Space Complexity : O(N)

//Circular queue is preferred because linear queues suffer from false overflow due to unused freed spaces, which is solved using a circular queue.
//In this implementation, queue of size n can store n-1 elements because one slot is always kept empty to distinguish full queue and empty queue.
