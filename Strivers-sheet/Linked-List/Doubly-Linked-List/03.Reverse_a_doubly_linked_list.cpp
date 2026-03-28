/*
QUESTION:-
You are given the head of a doubly linked list.
Reverse the list in-place and return the new head of the reversed list.

Example:

Input: head = [10, 20, 30]
Output:﻿ [30, 20, 10]
*/

/*
APPROACH:
1. We check if head == NULL. If yes, return NULL.
2. We create a new listnode, assigning it as head to traverse through the linked list.
3. We create a new listnode, newhead, which will save the value of the final head of the new linked list.
4. While curr != NULL, we save the value of the next listnode in temp, so as to not lose it.
5. We connect the next listnode as the prev listnode.
6. We connect the prev listnode as temp.
7. Update newhead to curr.
8. Move curr to the next listnode.
9. Return newhead {since after the final traversal, curr becomes NULL and newhead becomes the last node, now the first node}.
*/

//CODE:
class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {
        if(head == NULL) return NULL;

        ListNode* curr = head;
        ListNode* newhead = NULL;
        while(curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;

            newhead = curr;
            curr = curr->prev;
        }
        return newhead;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
