/*
QUESTION:-
Implement a Last-In-First-Out (LIFO) stack using a singly linked list. The implemented stack should support the following operations: push, pop, top, and isEmpty.

Example:

Input : ["mystack", "push", "push", "pop", "top", "isEmpty"]
        [[], [3], [7], [], [], []]
Output: [null, null, null, null, 3, false]

Explanation:
mystack stack = new mystack();
stack.push(3);
stack.push(7);
stack.pop();
stack.top(); // returns 3
stack.isEmpty(); // returns false
*/

/*
APPROACH:
1. We first create a struct Node to define the Node structure.
2. We create a head pointer for the stack struct and initialise it to nullptr.
3. To push, we create a new node temp with x as data. We insert that node at the head, and update the head to temp.
4. To pop, if head is nullptr, it gives stack underflow and return. Else, we save head in temp, and move head to the next node. Then, we delete temp.
5. To peek, we return head data. If head is nullptr, it gives stack underflow.
6. To check if stack is empty, if head is nullptr, return true. Else, return false.
*/

//CODE:
struct Node {
    int data;
    Node* next;    Node(int n) {
        data = n;
        next = nullptr;
    }
};

struct mystack {
    Node* head;

    mystack() {
        head = nullptr;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
    }

    void pop() {
        if (head == nullptr) {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int peek() {
        if (head == nullptr) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        cout << head->data << " is at the top" << endl;
        return head->data;
    }

    bool isEmpty() {
        if (head == nullptr) {
            cout << "Stack empty" << endl;
            return true;
        }
        cout << "Stack not empty" << endl;
        return false;
    }
};

//Time Complexity : O(1) {for all}
//Space Complexity : O(N)
