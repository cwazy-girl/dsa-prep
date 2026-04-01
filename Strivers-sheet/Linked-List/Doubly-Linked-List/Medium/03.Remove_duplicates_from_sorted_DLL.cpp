/*
QUESTION:-
Given the head of a doubly linked list with its values sorted in non-decreasing order. Remove all duplicate occurrences of any value in the list so that only distinct values are present in the list.
Return the head of the modified linked list.

Example:

Input: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5
Output: head -> 1 <-> 3 <-> 4 <-> 5
Explanation: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5
The underlined nodes were deleted to get the desired result.
*/

/*
APPROACH:
1. We initialise listnode move from head to traverse through the list.
2. If the linked list is NULL or has one node, return head.
3. Now, while move->next != NULL, we check if the val of the current node is equal to the val of the next node.
4. If yes, we connect move->next to move->next->next, and if move->next is not NULL, we connect move->next->prev to move.
5. Else, we shift move to the next node.
6. Return head.
*/

//CODE:
class Solution {
public:
    ListNode * removeDuplicates(ListNode *head) {
        ListNode* move = head;

        if(!head || !head->next) return head;

        while(move->next != NULL) {
            if(move->val == move->next->val) {
                move->next = move->next->next;
                if(move->next) move->next->prev = move;
            }
            else {
                move = move->next;
            }
        }
        return head;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
