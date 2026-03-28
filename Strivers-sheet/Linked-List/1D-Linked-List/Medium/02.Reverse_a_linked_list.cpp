/*
QUESTION:-
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/

/*
APPROACH:
1. We initialise two listnodes, one will indicate the prev node and the other will indicate the current listnode.
2. While curr != NULL, we initialise a listnode, which indicates the next listnode.
3. We point the next of current listnode to prev.
4. Update prev to curr listnode.
5. Move curr to temp.
6. Return prev.
*/

//CODE:
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
