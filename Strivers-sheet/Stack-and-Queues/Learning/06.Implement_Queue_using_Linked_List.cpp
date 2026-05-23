/*
QUESTION:-
Implement a First-In-First-Out (FIFO) queue using a singly linked list. The implemented queue should support the following operations: push, pop, peek, and isEmpty.

Example:

Input : ["myqueue", "push", "push", "peek", "pop", "isEmpty"]
        [[], [3], [7], [], [], []]
Output : [null, null, null, 3, 3, false]
Explanation:
myqueue queue = new myqueue();
queue.push(3);
queue.push(7);
queue.peek(); // returns 3
queue.pop(); // returns 3
queue.isEmpty(); // returns false
*/

/*
APPROACH:
1. We first create a struct Node to define the Node structure.
2. We create a front and rear pointer for the queue struct and initialise them to nullptr.
3. To push, we use rear pointer. If rear is nullptr, then we create a new node and assign it to rear, and then equate it to front. Else, we create a new node and assign it to rear->next, and then move rear to the next pointer.
4. To pop, we use front pointer. If front is nullptr, it gives queue underflow, and returns -1. Else, we save front pointer in temp, and move front to the next pointer. If that next pointer is nullptr, that means rear also has to come back to nullptr.
5. Then, delete temp and return temp->data.
6. To peek, we use front pointer. If front is nullptr, it gives queue underflow, and returns -1. Else, returns front->data.
7. To check if queue is empty, if front is nullptr, return true. Else, return false.
*/

//CODE:
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

struct myqueue {
    Node* front;
    Node* rear;

    myqueue() {
        front = nullptr;
        rear = nullptr;
    }

    void push(int x) {
        if (rear == nullptr) {
            rear = new Node(x);
            front = rear;
            return;
        }
        rear->next = new Node(x);
        rear = rear->next;
    }

    int pop() {
        if (front == nullptr) {
            cout << "Queue underflow" << endl;
            return -1;
        }
        Node* temp = front;
        int x = temp->data;
        front = front->next;

        if (front == nullptr) rear = nullptr;
        delete temp;
        return x;
    }

    int peek() {
        if (front == nullptr) {
            cout << "Queue underflow" << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

//Time Complexity : O(1) {for all}
//Space Complexity : O(N)
