/*
QUESTION:-
You are given the head of a singly linked list. Your task is to return the number of nodes in the linked list.

Example:

Input: head = [1, 2, 3, 4, 5]
Output: 5
*/

/*
APPROACH:
1. We initiate a variable count, from 0.
2. While head != NULL, we keep +1 to count, and moving head to the next node.
3. When head == NULL, all nodes will be traversed.
4. Return count.
*/

//CODE:
class Solution {
public:
    int getLength(ListNode* head) {
        int count = 0;
        while(head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
