/*
QUESTION:-
Given the head of a doubly linked list, remove the node at the head of the linked list and return the head of the modified list.

Example:

Input: doublyLinkedList = [1, 2, 3]
Output: [2, 3]
Explanation:
The node with value 1 was removed.
*/

/*
APPROACH:
1. If head == NULL, return NULL.
2. We assign the node value of head to temp.
3. We shift head to the next node.
4. If head != NULL, then we assign the prev value of head to NULL.
5. Delete temp.
6. Return head.
*/

//CODE:
class Solution {
public:
    ListNode *deleteHead(ListNode *&head) {
        if(head == NULL) return NULL;

        ListNode* temp = head;
        head = head->next;
        
        if(head != NULL) head->prev = NULL;

        delete temp;
        return head;
    }
};

//Time Complexity : O(1)
//Space Complexity : O(1)
