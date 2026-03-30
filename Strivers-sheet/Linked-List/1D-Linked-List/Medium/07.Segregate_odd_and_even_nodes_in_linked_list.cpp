/*
QUESTION:-
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.

Example:

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
*/

/*
APPROACH:
1. If a linked list is NULL or has one node, then we can just return head, because then the nodes are already sorted as given.
2. Now, we create three nodes, odd {to track odd nodes}, even {to track even nodes} and newhead {to save the head of the linked list of even nodes}.
3. While we traverse the linked list, we assign the next of odd node as even->next. And then we shift the odd to that value.
4. Similarly, we assign the next of even to odd->next, and then we shift the even to that value.
5. Like this, we traverse through the entire linked list, and we connected odd and even terms together.
6. Now we connect the last node of odd values {saved by odd} to the head of even nodes {newhead}.
7. Return head.
*/

//CODE:
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* newhead = even;

        while(even != NULL && even->next != NULL) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = newhead;
        return head;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
